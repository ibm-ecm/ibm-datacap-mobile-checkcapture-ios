//
//  ICPSetupDCO.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 *  The Setup DCO
 */
@protocol ICPSetupDCO <NSObject>

/**
 *  The Setup DCO name that corresponds to the DCO file on the server
 */
@property (nonatomic, strong, readonly) NSString *name;

@end

NS_ASSUME_NONNULL_END
