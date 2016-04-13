//
//  ICPDatacapSessionManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPLoginProvider.h"

NS_ASSUME_NONNULL_BEGIN

@class IBMDatacap;

@protocol ICPDatacapService;
@protocol ICPObjectFactory;

/**
 The ICPDatacapLoginProvider is an implementation of ICPLoginProvider for <a src="http://www-03.ibm.com/software/products/en/datacap">Datacap</a>
 
 @see ICPLoginProvideer
 */
@interface ICPDatacapLoginProvider : NSObject <ICPLoginProvider>

- (instancetype) init NS_UNAVAILABLE;

/**
 
 @param credential      NSURLCredential that will be used to authenticate the user
 @param datacap         IBMDatacap that will handle the requests to the datacap server
 @param service         ICPDatacapService with the server configuration
 @param objectFactory   Application's ICPObjectFactory
 @param delegate        Object that will be notified for each step of the authentication
 
 @return An ICPDatacapLoginProvider instance
 */
- (instancetype) initWithURLCredential:(NSURLCredential *)credential
                               datacap:(IBMDatacap *)datacap
                               service:(id<ICPDatacapService>)service
                         objectFactory:(id<ICPObjectFactory>)objectFactory
                           andDelegate:(_Nullable id<ICPLoginProviderDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
