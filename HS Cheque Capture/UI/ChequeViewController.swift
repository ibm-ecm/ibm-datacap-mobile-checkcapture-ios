//
//  ChequeVerificationView.swift
//  HS Cheque Capture
//
//  Created by Daniel Crow on 02/02/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import UIKit

class ChequeViewController: UIViewController {

    typealias KeyValue = (key : String, value : String?)
    
    @IBOutlet weak private var tableView: UITableView!
    
    private var cheque = Cheque()
    private var chequeValues = [KeyValue]()
    private let noChequeImage = UIImage(named: "overlaygraphic")
    
    lazy private var chequeZones : ChequeZonalTemplate = {
        
        let refSize : CGSize = CGSize(width: 2551, height: 1061)
        let signatureRect = CGRect(x: 1653.0, y: 721.0, width: 827.0, height: 118.0)
        let micrRect = CGRect(x: 0, y: 881.0, width: 2551.0, height: 180.0)
        let nameRect = CGRect(x: 1951.0, y: 605.0, width: 600.0, height: 100.0)
        return ChequeZonalTemplate(refSize: refSize, signatureRect: signatureRect, micrRect: micrRect, nameRect: nameRect)
        
    }()
    
    lazy private var chequeProcessor : ChequeProcessor = {
        return ChequeProcessor(chequeZones: self.chequeZones)
    }()
    
    private var hud : MBProgressHUD?    

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = NSLocalizedString("Cheque", comment: "")

    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if let navController = segue.destinationViewController as? UINavigationController  {
            if let cameraController = navController.viewControllers[0] as? CameraViewController, let indexPath = sender as? NSIndexPath {
            
                if indexPath.row == 0 {
                    
                    cameraController.chequeZones = self.chequeZones
                    cameraController.title = NSLocalizedString("Front of cheque", comment: "")
                    cameraController.instruction = NSLocalizedString("Capture front of cheque", comment: "")
                    cameraController.completionBlock = {[unowned self] image in
                        if let image = image {
                            self.capturedFront(image)
                        }
                        
                    }
                }else{
                    cameraController.title = NSLocalizedString("Back of cheque", comment: "")
                    cameraController.instruction = NSLocalizedString("Capture back of cheque", comment: "")
                    cameraController.completionBlock = {[unowned self] image in
                        if let image = image {
                            self.capturedBack(image)

                        }
                    }
                }
            }
        }
    }
}

extension ChequeViewController {

    private func populateChequeData(){
        
        self.chequeValues = [KeyValue]()
        
        self.chequeValues.append((NSLocalizedString("Cheque Number", comment: ""), self.cheque.chequeNumber))
        self.chequeValues.append((NSLocalizedString("Account Number", comment: ""), self.cheque.accountNumber))
        self.chequeValues.append((NSLocalizedString("Sort Code", comment: ""), self.cheque.sortCode))
        self.chequeValues.append((NSLocalizedString("Signature", comment: ""), self.cheque.signatureCheck.description))
        self.chequeValues.append((NSLocalizedString("Amount", comment: ""), self.cheque.amount))
        self.chequeValues.append((NSLocalizedString("Pay Name", comment: ""), self.cheque.payName))
        self.chequeValues.append((NSLocalizedString("CAR", comment: ""), self.cheque.CAR))
        self.chequeValues.append((NSLocalizedString("LAR", comment: ""), self.cheque.LAR))
        self.chequeValues.append((NSLocalizedString("Doc Type", comment: ""), self.cheque.docType))
    }
    
    private func capturedFront(image : UIImage?){
        self.cheque.frontOfChequeImage = image
        self.processFrontOfCheck()
    }
    
    private func capturedBack(image : UIImage?){
        self.cheque.backOfChequeImage = image
        self.processFrontOfCheck()
    }
    
    private func processFrontOfCheck(){
        
        self.tableView.reloadData()
        
        if let image = self.cheque.frontOfChequeImage where self.cheque.hasBackAndFront{
            self.getMICR(image)
        }
    }
    
    private func getMICR(image : UIImage){
        
        self.hud = MBProgressHUD.showHUDAddedTo(self.view, animated: true)
        self.hud?.labelText = NSLocalizedString("Reading MICR ...", comment: "")
        
        self.chequeProcessor.processFrontOfCheque(image) {[unowned self] (micr) in
            
            if let micr = micr {
                self.cheque.accountNumber = micr.accountNumber
                self.cheque.sortCode = micr.sortCode
                self.cheque.chequeNumber = micr.chequeNumber
                self.cheque.accountNumber = micr.accountNumber
            }
            
            self.getPayName(image)
            
        }
    
    }
    
    private func getPayName(image : UIImage){
        
        self.hud?.labelText = NSLocalizedString("Reading Pay Name ...", comment: "")
        
        self.chequeProcessor.getPayName(image, completionBlock: {[unowned self] (payName) in
            
            self.cheque.payName = payName
            
            self.getSignature(image)
        })
    
    }
    
    private func getSignature(image : UIImage){
        
        self.hud?.labelText = NSLocalizedString("Checking Signature ...", comment: "")
        
        self.chequeProcessor.getSignatureCheck(image) { (isSigned) in
            self.cheque.signatureCheck = isSigned
            
            self.getAmount(image)
        }
        
    }
    
    private func getAmount(image : UIImage){
        
        self.hud?.labelText = NSLocalizedString("Reading Amount ...", comment: "")
        
        self.chequeProcessor.getAmounts(image) { (chequeInfo) in
            
            if let chequeInfo = chequeInfo {
                self.cheque.amount = chequeInfo.amount
                self.cheque.CAR = chequeInfo.car
                self.cheque.LAR = chequeInfo.lar
                self.cheque.docType = chequeInfo.docType
            }

            self.hud?.hide(true)
            self.populateChequeData()
            self.tableView.reloadData()
        }
        
    }
}

extension ChequeViewController : UITableViewDataSource{

    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 2
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        if section == 0{
            return self.cheque.frontOfChequeImage == nil ? 1 : 2
        }else{
            return self.cheque.backOfChequeImage == nil ? 0 : self.chequeValues.count
        }

    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        if indexPath.section == 0 {
        
            let cell = tableView.dequeueReusableCellWithIdentifier(String(ChequeCell), forIndexPath: indexPath) as! ChequeCell
            
            if indexPath.row == 0 {
                cell.chequeImageView.image = self.cheque.frontOfChequeImage == nil ? self.noChequeImage : self.cheque.frontOfChequeImage
                cell.chequeLabel.text = self.cheque.frontOfChequeImage == nil ? NSLocalizedString("Add Front of Cheque", comment: "") : NSLocalizedString("Front of cheque", comment: "")
            }else{
                cell.chequeImageView.image = self.cheque.backOfChequeImage == nil ? self.noChequeImage : self.cheque.backOfChequeImage
                cell.chequeLabel.text = self.cheque.backOfChequeImage == nil ? NSLocalizedString("Add Back of cheque", comment: "") : NSLocalizedString("Back of cheque", comment: "")
            }
            
            return cell
            
        }else{
        
            let cell = tableView.dequeueReusableCellWithIdentifier("Detail", forIndexPath: indexPath)
            
            let data = self.chequeValues[indexPath.row]
            
            cell.textLabel?.text = data.key
            cell.detailTextLabel?.text = data.value
            
            return cell
            
        }
        
    }
    
}

extension ChequeViewController : UITableViewDelegate {

    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)
        
        self.performSegueWithIdentifier("presentCamera", sender: indexPath)
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return indexPath.section == 0 ? 80.0 : 44.0
    }
    
    func tableView(tableView: UITableView, shouldHighlightRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        return indexPath.section == 0
    }
    
}

class ChequeCell: UITableViewCell {
    
    @IBOutlet weak var chequeImageView: UIImageView!
    @IBOutlet weak var chequeLabel: UILabel!
    
}
