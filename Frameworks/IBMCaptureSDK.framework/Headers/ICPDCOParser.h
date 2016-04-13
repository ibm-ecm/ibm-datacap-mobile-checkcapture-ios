//
//  ICPDCOParser.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPConfigurationParser.h"

@protocol ICPObjectFactory;

NS_ASSUME_NONNULL_BEGIN

/**
 The ICPDCOParser is an implementation of the ICPConfigurationParser.
 This parser is responsable to read a XML file that follows the DCO format
 
 @see ICPConfigurationParser
 */
@interface ICPDCOParser : NSObject <ICPConfigurationParser>

- (instancetype)init NS_UNAVAILABLE;

/** 
 The ICPDCOParser designated initializer requires an ICPOBjectFactory to be able to create 
 and configure the objects listed on the dco configuration file.
 
 @param objectFactory   The ICPObjectFactory responsable to control the objects lifecycle
 @return An instance of ICPDCOParser
 */
- (instancetype)initWithObjectFactory:(id<ICPObjectFactory>)objectFactory NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
