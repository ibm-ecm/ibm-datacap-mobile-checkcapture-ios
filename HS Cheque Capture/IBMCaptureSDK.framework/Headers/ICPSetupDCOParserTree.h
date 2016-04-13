//
//  ICPSetupDCOParserTree.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPDCOParserTree.h"

@protocol ICPObjectFactory;

NS_ASSUME_NONNULL_BEGIN

/**
 This class is an implementation of the ICPDCOParserTree, being responsable to parse a Setup DCO xml file
 
 @see ICPSetupDCO
 */
@interface ICPSetupDCOParserTree : NSObject <ICPDCOParserTree>

- (instancetype)init NS_UNAVAILABLE;

/**
 The ICPSetupDCOParserTree designated initializer requires an ICPOBjectFactory to be able to create
 and configure the objects listed on the dco configuration file.
 
 @param objectFactory   The ICPObjectFactory responsable to control the objects lifecycle
 @return An instance of ICPSetupDCOParserTree
 */
- (instancetype)initWithObjectFactory:(id<ICPObjectFactory>)objectFactory NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
