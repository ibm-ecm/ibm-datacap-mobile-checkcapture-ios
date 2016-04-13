//
//  ICPSessionManager+Datacap.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import "ICPSessionManager.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPDatacapService;

@interface ICPSessionManager (Datacap)

/**
 This method is responsable for create an ICPSessionManager configurated to use the Datacap server to access and storage files
 
 @param credential      NSURLCredential that will be used to authenticate the user
 @param service         ICPDatacapService with the server configuration
 @param objectFactory   Application's ICPObjectFactory
 
 @return An ICPSessionManager instance, configured for a datacap server
 */
+ (instancetype) sessionManagerWithObjectFactory:(id<ICPObjectFactory>)objectFactory
                                         service:(id<ICPDatacapService>)service
                                  andCredentials:(NSURLCredential *)credential;

/**
 This ICPRemoteComputationManager is an object configurated to perform page transactions on the Datacap server
 
 @see ICPRemoteComputationManager
 
 @return An ICPRemoteComputationManager instance, configured to the ICPSessionManager datacap server
 */
- (ICPRemoteComputationManager *)datacapRemoteComputationManager;

@end

NS_ASSUME_NONNULL_END
