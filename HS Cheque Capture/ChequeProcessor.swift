//
//  ChequeProcessor.swift
//  HS Cheque Capture
//
//  Created by Julien Hebert on 13/04/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import IBMCaptureSDK

class ChequeProcessor {

    typealias MICR = (chequeNumber : String, sortCode : String, accountNumber : String)
    typealias ChequeInfo = (amount : String?, car : String?, lar : String?, docType : String?)
    
    private var chequeZones : ChequeZonalTemplate
    
    private let datacapServiceConfig = DataCapServiceConfiguration()
    
    private var sessionManager : ICPSessionManager!
    
    lazy private var chequeOCREngine : ICPOcrEngine = {
        return ICPTesseractOcrEngine(tessDataPrefixes: ["mcr"], andTessdataAbsolutePath: NSBundle.mainBundle().bundlePath)
    }()
    
    lazy private var englishOCREngine : ICPOcrEngine = {
        return ICPTesseractOcrEngine(tessDataPrefixes: ["eng"], andTessdataAbsolutePath: NSBundle.mainBundle().bundlePath)
    }()
    
    lazy private var imageEngine : ICPImageEngine = {
        return ICPCoreImageImageEngine()
    }()
    
    lazy private var remoteComputationManager : ICPRemoteComputationManager = { [unowned self] in
        return self.datacapServiceConfig.remoteComputationManager
        }()
    
    init(chequeZones : ChequeZonalTemplate) {
        self.chequeZones = chequeZones
    }
    
    
    //MARK: Internal methods
    
    func processFrontOfCheque(image : UIImage, completionBlock : MICR? -> Void){
        
        let rect:CGRect = self.chequeZones.micrRect(image.size)
        
        self.chequeOCREngine.recognizeTextInImage(image, withRect: rect, whitelist: nil, highlightChars: false, completionBlock: {(image:UIImage, text:String, metadata:[String : [AnyObject]])  -> Void in
            
            completionBlock(self.parseMICR(text))
        
        })
        
    }
    
    func getPayName(image : UIImage, completionBlock : String? -> Void){
        
        self.imageEngine.applyFilter(ICPFilterType.BlackAndWhite, toImage: image) {[unowned self] (bwImage:UIImage?) in
            
            let payRect = self.chequeZones.nameRect(image.size)
            
            self.englishOCREngine.recognizeTextInImage(image, withRect: payRect, whitelist: "ABCDEFGHIJKLMNOPQRSTUVWXYZ", highlightChars: false, completionBlock: {(image:UIImage, text:String, metadata:[String : [AnyObject]])  -> Void in
                
                completionBlock(text)
                
            })
        }
        
    }
    
    func getSignatureCheck(image : UIImage, completionBlock : Bool -> Void){
        
        self.imageEngine.applyFilter(ICPFilterType.BlackAndWhite, toImage: image) {[unowned self] (image : UIImage?) in
            
            guard let bwImage = image else {
                completionBlock(false)
                return
            }
            
            let rect = self.chequeZones.signatureRect(bwImage.size)
            
            self.englishOCREngine.recognizeTextInImage(bwImage, withRect: rect, whitelist: nil, highlightChars: false, completionBlock: {(image:UIImage, texts:String, metadata:[String : [AnyObject]])  -> Void in

                completionBlock(texts.characters.count > 0)

            })
        }
    }
    
    func getAmounts(image : UIImage, completionBlock : (ChequeInfo?) -> Void){
        
        let capture = self.datacapServiceConfig.capture
        
        let objectFactory = capture.objectFactory!
        
        let rotatedImage = image.fixOrientation()
        
        let page = objectFactory.pageWithDocument(nil, type: nil)
        page.modifiedImage = rotatedImage
        
        let chequeFields = ["Amount", "DocumentType", "CAR", "LAR"]
        
        for fieldName in chequeFields {
            let fieldType = objectFactory.fieldTypeWithTypeId(fieldName)
            objectFactory.fieldWithObject(page, type: fieldType)
        }
        
        self.remoteComputationManager.processCheck(page, checkCountry: .UK, keepAlive: false) { (success:Bool, fields : [ICPField], error:NSError?) in
            
            if success {
                
                self.remoteComputationManager.updatePage(page, withResults: fields, skipNonBlankFields: false, andCompletionBlock: { (success:Bool, page:ICPPage, error:NSError?) in
                    
                    if(success && page.fields.count>0){
                        completionBlock(self.parseChequeInfo(page.fields))
                    }else{
                        print(error?.description)
                        completionBlock(nil)
                    }
                    
                })
                
            } else {
                print(error?.description)
                completionBlock(nil)
            }
        }
    }
    
    //MARK: Private functions
    
    private func parseChequeInfo(fields:[ICPField]) -> ChequeInfo? {
        var amount : String?
        var car : String?
        var lar : String?
        var docType : String?
        
        for field in fields{
            
            if let value = field.value as? String, let fieldType = field.type{
                
                switch fieldType.typeId {
                    case "Amount": amount = value
                    case "CAR": car = value
                    case "LAR": lar = value
                    case "DocumentType": docType = value
                    default: break
                }
                
            }
            
        }
        
        return (amount, car, lar, docType)
    }
    
    private func parseMICR (micr : String) -> MICR? {
        
        let components = micr.componentsSeparatedByString("@")
        if components.count > 2 {
            let chequeNumber = components[1].stringByReplacingOccurrencesOfString(" ", withString: "")
            let component = components[2]
            let components2 = component.componentsSeparatedByString("[")
            if components2.count > 1 {
                let sortCode = components2[0].stringByReplacingOccurrencesOfString(" ", withString: "").stringByReplacingOccurrencesOfString("-", withString: "")
                let accountNumber = components2[1].stringByReplacingOccurrencesOfString(" ", withString: "")
                return (chequeNumber, sortCode, accountNumber)
            }
        }
        return nil
        
    }
     
}

extension UIImage {
    
    func fixOrientation() -> UIImage {
    
        if (self.imageOrientation == .Up) {
            return self
        }
        
        let rect = CGRect(origin: CGPointZero, size: self.size)
        UIGraphicsBeginImageContextWithOptions(self.size, false, self.scale)
        self.drawInRect(rect)
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image
    }
}

