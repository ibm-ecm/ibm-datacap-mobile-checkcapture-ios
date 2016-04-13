//
//  ICPDCOBatchParser.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPObjectParser.h"

@protocol ICPObjectFactory;

/** 
 This class is an implementation of ICPObjectParser responsable to create a xml file that follows the DCO format
 */
@interface ICPDCOObjectParser : NSObject <ICPObjectParser>

@end
