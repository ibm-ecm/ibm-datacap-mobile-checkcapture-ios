//
//  ICPDatacapDCOManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPConfigurationProvider.h"

NS_ASSUME_NONNULL_BEGIN

@class IBMDatacap;
@class ICPDatacapResponseHandler;
@protocol ICPDatacapService;
@protocol ICPLoginProvider;

/**
 The ICPDatacapConfigurationProvider is an implementation of ICPConfigurationProvider responsable for
 retrieving the configuration files from the Datacap server.
 
 @see ICPConfigurationProvider
 */
@interface ICPDatacapConfigurationProvider : NSObject <ICPConfigurationProvider>

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPBoxConfigurationProvider is an implementation of ICPConfigurationProvider responsable for
 retrieving the configuration files from the Datacap server.
 
 @param datacap         IBMDatacap that will handle the requests to the datacap server
 @param responseHandler ICPDatacapResponseHandler that will handle the response from the server
 @param service         ICPDatacapService with the server configuration
 @param loginProvider   ICPLoginProvider used to authenticate in the datacap server
 
 @return An ICPDatacapConfigurationProvider instance
 */
- (instancetype)initWithDatacap:(IBMDatacap*)datacap
                responseHandler:(ICPDatacapResponseHandler *)responseHandler
                        service:(id<ICPDatacapService>)service
               andLoginProvider:(id<ICPLoginProvider>)loginProvider NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
