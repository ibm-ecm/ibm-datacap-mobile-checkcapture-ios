//
//  ICPSessionManager+Box.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import "ICPSessionManager.h"
#import "ICPBoxLoginProvider.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPObjectFactory;

@interface ICPSessionManager (Box)

/**
 This method is responsable for create an ICPSessionManager configurated to use the Box SDK to access and storage files
 
 @param objectFactory           Application's ICPObjectFactory
 @param authType                ICPBoxLoginProviderAuthType used to authenticate the user
 @param accessTokenOperation    Block used to request the app to retrieve the user access token when using ICPBoxLoginProviderAuthTypeAPIKey
 
 @see ICPBoxLoginProvider
 @see ICPBoxStorageProvider
 @see ICPBoxConfigurationProvider
 
 @return An ICPSessionManager with all the providers configured to Box
 */
+ (instancetype) sessionManagerWithObjectFactory:(id<ICPObjectFactory>)objectFactory
                                        authType:(ICPBoxLoginProviderAuthType)authType
                         andAccessTokenOperation:(_Nullable ICPBoxLoginProviderAccessTokenOperation)accessTokenOperation;

@end

NS_ASSUME_NONNULL_END
