//
//  ICPDatacapHelper.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPCaptureCompletionBlock.h"
#import "ICPServerHelper.h"
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@protocol ICPDatacapService
, ICPApplication, ICPWorkflow, ICPStation, ICPJob, ICPSetupDCO;

/**
 *  Completion block for getStations
 *
 *  @param success  YES if server request returned successfully
 *  @param stations The list of stations
 *  @param error    Returns error if success is NO
 */
typedef void (^ICPGetStationsCompletionBlock)(BOOL success,
                                                  NSArray<id<ICPStation> > *_Nullable stations,
                                                  NSError *_Nullable error);

/**
 *  Completion block for getWorkflows
 *
 *  @param success   YES if server request returned successfully
 *  @param workflows The list of workflows
 *  @param error     Returns error if success is NO
 */
typedef void (^ICPGetWorkflowsCompletionBlock)(BOOL success,
                                                   NSArray<id<ICPWorkflow> > *_Nullable workflows,
                                                   NSError *_Nullable error);

/**
 *  Completion block for getJobs
 *
 *  @param success YES if server request returned successfully
 *  @param jobs    The list of jobs
 *  @param error   Returns error if success is NO
 */
typedef void (^ICPGetJobsCompletionBlock)(BOOL success, NSArray<id<ICPJob> > *_Nullable jobs, NSError *_Nullable error);

/**
 *  Completion block for getSetupDCOs
 *
 *  @param success   YES if server request returned successfully
 *  @param setupDCOs The list of setupDCOs
 *  @param error     Returns error if success is NO
 */
typedef void (^ICPGetSetupDCOsCompletionBlock)(BOOL success,
                                               NSArray<id<ICPSetupDCO> > *_Nullable setupDCOs,
                                               NSError *_Nullable error);

/**
    The ICPDatacapHelper class provides miscellaneous networking methods that are specific to IBM Datacap.
    Methods that are more general and might in the future apply to other remote services (for example: IBM Navigator) can be
   found in the ICPServiceClient protcol.
 */
@interface ICPDatacapHelper : NSObject <ICPServerHelper>

/**
 *  The remote service to which this helper instance connects.
 */
@property (nonatomic, strong, readonly, nullable) id<ICPDatacapService> service;

/**
 *  Creates an instance of the ICPDatacapHelper class with service and credential information.
 *
 *  @param service    The remote service.
 *  @param objectFactory The object factory
 *  @param credential The credentials needed to connect to the remote service.
 *
 *  @return An instance of the ICPDatacapHelper class.
 */
- (instancetype)initWithDatacapService:(id<ICPDatacapService>)service
                         objectFactory:(id<ICPObjectFactory>)objectFactory
                            credential:(NSURLCredential *)credential;

/**
 Gets a list station IDs from the remote service.

 @param application The application for which to retrieve station IDs.
 @param completionBlock The completion block.
 */
- (void)getStationListForApplication:(id<ICPApplication>)application
                     completionBlock:(ICPGetStationsCompletionBlock)completionBlock;

/**
 Gets a list of workflows for the application from the remote service.

 @param application The application.
 @param completionBlock The completion block.
 */
- (void)getWorkflowListForApplication:(id<ICPApplication>)application
                      completionBlock:(ICPGetWorkflowsCompletionBlock)completionBlock;

/**
 Gets a list of jobs for the application and workflow from the remote service.

 @param application The application.
 @param workflowIndex The workflow index.
 @param completionBlock The completion block.
 */
- (void)getJobListForApplication:(id<ICPApplication>)application
                        workflow:(id<ICPWorkflow>)workflow
                 completionBlock:(ICPGetJobsCompletionBlock)completionBlock;

/**
 Gets a list of DCOs for the application from the remote service.

 @param application The application.
 @param completionBlock The completion block.
 */
- (void)getSetupDCOsForApplication:(id<ICPApplication>)application
                  completionBlock:(ICPGetSetupDCOsCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
