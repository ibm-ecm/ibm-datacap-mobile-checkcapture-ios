//
//  CapureImageViewController.swift
//  HS Cheque Capture
//
//  Created by Daniel Crow on 01/02/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//


import UIKit

class CapureImageViewController: UIViewController {
    
    @IBOutlet weak var textLabel: UILabel!
    @IBOutlet weak var imageView: UIImageView!
    
    var completionBlock : (UIImage? -> Void)!
    var image : UIImage?
    var chequeZones : ChequeZonalTemplate?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.imageView.image = self.image
        
        self.setupNavigationBar()
    }
    
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        
        if let chequeZones = self.chequeZones , let image = self.image{
        
            self.imageView.image = image.addZonesToImage(chequeZones.allRects(image.size))
            
        }
    }
    
}

extension CapureImageViewController {

    private func setupNavigationBar(){
        
        let doneButton = UIBarButtonItem(barButtonSystemItem: .Done, target: self, action: #selector(CapureImageViewController.done))
        self.navigationItem.rightBarButtonItem = doneButton
        
    }
    
    func done(){
        self.completionBlock(self.image)
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    
}

extension UIImage {
    
    func addZonesToImage(rects : [CGRect]) -> UIImage {
        
        UIGraphicsBeginImageContext(self.size)
        
        let context  = UIGraphicsGetCurrentContext()
        
        self.drawInRect(CGRect(x: 0, y: 0, width: self.size.width, height: self.size.height))
        
        let strokeColor = UIColor.redColor()
        
        CGContextSetLineWidth(context, 1.0)
        CGContextSetStrokeColorWithColor(context, strokeColor.CGColor)
        
        for rect in rects {
            CGContextStrokeRectWithWidth(context, rect, 5.0)
        }
        
        let result = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return result
        
    }
    
}
