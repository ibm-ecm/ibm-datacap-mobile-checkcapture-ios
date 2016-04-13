//
//  ChequeZonalTemplate.swift
//  HS Cheque Capture
//
//  Created by Julien Hebert on 13/04/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import UIKit

struct ChequeZonalTemplate {
    
    private var refSize = CGSizeZero
    private var signatureRect = CGRectZero
    private var micrRect = CGRectZero
    private var nameRect = CGRectZero
    
    init(refSize : CGSize, signatureRect : CGRect, micrRect : CGRect, nameRect : CGRect) {
        self.refSize = refSize
        self.signatureRect = signatureRect
        self.micrRect = micrRect
        self.nameRect = nameRect
    }
    
    func signatureRect(forImageSize : CGSize) -> CGRect {
        return self.convertRect(self.signatureRect, fromSize: self.refSize, toSize: forImageSize)
    }
    
    func micrRect(forImageSize : CGSize) -> CGRect {
        return self.convertRect(self.micrRect, fromSize: self.refSize, toSize: forImageSize)
    }
    
    func nameRect(forImageSize : CGSize) -> CGRect {
        return self.convertRect(self.nameRect, fromSize: self.refSize, toSize: forImageSize)
    }
    
    func allRects(forImageSize : CGSize) -> [CGRect] {
    
        var rects = [CGRect]()
        
        rects.append(self.signatureRect(forImageSize))
        rects.append(self.micrRect(forImageSize))
        rects.append(self.nameRect(forImageSize))
        
        return rects
        
    }

}

extension ChequeZonalTemplate {
    
    private func convertRect(rect : CGRect, fromSize: CGSize, toSize: CGSize) -> CGRect {
        
        let x : CGFloat = (rect.origin.x / fromSize.width) * toSize.width;
        let y : CGFloat = (rect.origin.y / fromSize.height) * toSize.height;
        let w : CGFloat = (rect.size.width / fromSize.width) * toSize.width;
        let h : CGFloat = (rect.size.height / fromSize.height) * toSize.height;
        
        return CGRectMake(x, y, w, h)
    }
    
}
