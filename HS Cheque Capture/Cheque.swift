//
//  Cheques.swift
//  HS Cheque Capture
//
//  Created by Daniel Crow on 01/02/2016.
//  Copyright © 2016 Daniel Crow. All rights reserved.
//

import Foundation

struct Cheque {
    
    var frontOfChequeImage : UIImage?
    var backOfChequeImage : UIImage?
    var chequeNumber : String?
    var signatureCheck : Bool = false
    var amount : String?
    var payName : String?
    var CAR : String?
    var LAR : String?
    var docType : String?
    var sortCode : String?
    var accountNumber : String?
    
    var hasBackAndFront : Bool {
        get {
            return self.frontOfChequeImage != nil && self.backOfChequeImage != nil
        }
    }
    
}