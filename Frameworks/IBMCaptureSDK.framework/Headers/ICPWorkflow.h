//
//  ICPWorkflow.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPIndex.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The workflow associated to the application
 */

@protocol ICPWorkflow <NSObject>

/**
 *  The workflowId
 */
@property (nonatomic, strong, readonly) NSString *workflowId;

/**
 *  The workflow index on Datacap server
 */
@property (nonatomic, assign, readonly) ICPIndex index;

@end

NS_ASSUME_NONNULL_END
