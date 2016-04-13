//
//  ICPServerHelper.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPCaptureCompletionBlock.h"

@protocol ICPApplication;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Completion block for getApplications
 *
 *  @param success      YES if server request returned successfully
 *  @param applications The list of applications
 *  @param error        Returns error if success is NO
 */
typedef void (^ICPGetApplicationsCompletionBlock)(BOOL success,
                                                  NSArray<id<ICPApplication>> *applications,
                                                  NSError *_Nullable error);

@protocol ICPServerHelper <NSObject>

/**
 Gets a list of applications from the remote service.
 
 @param completionBlock The completion block.
 */
- (void)getApplicationListWithCompletionBlock:(ICPGetApplicationsCompletionBlock)completionBlock;

/**
 Logoff from the service. This remove the session cookie on success
 
 @param completionBlock The completion block
 */
- (void)logoffWithCompletionBlock:(nullable ICPCaptureCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
