//
//  ICPApplication.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 *  An application defined in the Datacap Application Manager
 */
@protocol ICPApplication <NSObject>

/**
 *  The name of the Application
 */
@property (nonatomic, strong, readonly) NSString *name;

@end

NS_ASSUME_NONNULL_END
