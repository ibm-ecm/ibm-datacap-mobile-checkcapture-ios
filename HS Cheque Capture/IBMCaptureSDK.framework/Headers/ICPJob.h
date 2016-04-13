//
//  ICPJob.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPIndex.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Job associated with a workflow
 */

@protocol ICPJob <NSObject>

/**
 *  The job Id
 */
@property (nonatomic, strong, readonly) NSString *jobId;

/**
 *  The job index on Datacap server
 */
@property (nonatomic, assign, readonly) ICPIndex index;

@end

NS_ASSUME_NONNULL_END
