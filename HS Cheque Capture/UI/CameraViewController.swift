//
//  CameraViewController.swift
//  HS Cheque Capture
//
//  Created by Daniel Crow on 01/02/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import UIKit
import IBMCaptureUISDK

class CameraViewController: UIViewController {
    
    var instruction : String!
    var completionBlock : (UIImage? -> Void)!
    var chequeZones : ChequeZonalTemplate?
    
    @IBOutlet private weak var cameraView:ICPCameraView!
    @IBOutlet private weak var captureLabel: UILabel!
    @IBOutlet private weak var messageLabel: UILabel!
    
    private var image : UIImage?
    private let showPictureSegue = "showPicture"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.configureCameraView()
        
        self.setupNavigationBar()
        
        self.setupUI()
        
        self.messageLabel.text = self.instruction
        
    }
    
    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        
        self.cameraView.restartPreview()
        
    }
    
    override func viewWillDisappear(animated: Bool) {
        super.viewWillDisappear(animated)
        
        self.cameraView.stopPreview()
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if let captureImageViewController = segue.destinationViewController as? CapureImageViewController {
            captureImageViewController.completionBlock = self.completionBlock
            captureImageViewController.image = self.image
            captureImageViewController.chequeZones = self.chequeZones
        }
    }

}

extension CameraViewController {
    
    private func setupUI(){
        
        self.captureLabel.textColor = UIColor.whiteColor()
        self.captureLabel.backgroundColor = UIColor.blackColor().colorWithAlphaComponent(0.3)
        self.messageLabel.textColor = UIColor.whiteColor()
        self.messageLabel.backgroundColor = UIColor.blackColor().colorWithAlphaComponent(0.3)
        
    }

    private func configureCameraView(){
        self.cameraView.automaticallyDetectDocuments = true
        self.cameraView.delegate = self
        self.cameraView.minimumScreenPercentage = 0.5
        self.cameraView.maximumAspectRatio = 6
        self.cameraView.minimumAspectRatio = 0.2
        self.cameraView.accelerationThreshold = 0.1
    }
    
    private func setupNavigationBar(){
    
        let cancelButton = UIBarButtonItem(barButtonSystemItem: .Cancel, target: self, action: #selector(CameraViewController.cancel))
        self.navigationItem.leftBarButtonItem = cancelButton
        
    }
    
    func cancel(){
        self.completionBlock(nil)
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    
}

extension CameraViewController : ICPCameraViewDelegate {

    func cameraViewDidDetectDocument(cameraView: ICPCameraView) {
        
        MBProgressHUD.showHUDAddedTo(self.view, animated: true)
        
        self.cameraView.takePhoto()
        
    }
    
    func cameraView(cameraView: ICPCameraView, didChangeState cameraState: ICPCameraViewState) {
        
        if (cameraState == .LookingForDocument) {
            self.captureLabel.text = NSLocalizedString("Looking for document ...", comment: "")
        }else if(cameraState == .CameraMoving){
            self.captureLabel.text = NSLocalizedString("Hold camera in place", comment: "")
        }else if(cameraState == .InvalidRatio){
            self.captureLabel.text = NSLocalizedString("Document has invalid aspect ratio", comment: "")
        }else if(cameraState == .DocumentTooSmall){
            self.captureLabel.text = NSLocalizedString("Bring camera closer", comment: "")
        }else if(cameraState == .DocumentDetected){
            self.captureLabel.text = NSLocalizedString("Document Detected", comment: "")
        }else if(cameraState == .CannotDetectTextInDocument){
            self.captureLabel.text = NSLocalizedString("Cannot detect text", comment: "")
        }else{
            self.captureLabel.text = ""
        }
    }
    
    func cameraView(cameraView: ICPCameraView, didTakeOriginalPhoto originalPhoto: UIImage?, modifiedPhoto: UIImage?) {
     
        MBProgressHUD.hideAllHUDsForView(self.view, animated: true)
        
        if let image = modifiedPhoto {
            self.image = image
            self.performSegueWithIdentifier(showPictureSegue, sender: nil)
        }
        
    }
    
}
