//
//  ICPBoxSessionManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPLoginProvider.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ICPBoxLoginProviderAccessTokenResponse)(NSString * _Nullable accessToken, NSDate * _Nullable expirationDate, NSError * _Nullable error);
typedef void(^ICPBoxLoginProviderAccessTokenOperation)(ICPBoxLoginProviderAccessTokenResponse response);

/**
 The BOX API have two types of authentitcation. 
 OAuth and <a src="https://box-content.readme.io/v2.0/docs/app-auth">App auth</a>.
 */
typedef NS_ENUM(NSUInteger, ICPBoxLoginProviderAuthType) {
    /** The ICPBoxLoginProviderAuthTypeOAuth configures the provider to use the BOX website to authenticate the user */
    ICPBoxLoginProviderAuthTypeOAuth = -1002,
    /** The ICPBoxLoginProviderAuthTypeAPIKey configures the provider to request for the application for a valid access token */
    ICPBoxLoginProviderAuthTypeAPPAuth = -1003
};

/**
 The ICPBoxLoginProvider is an implementation of ICPLoginProvider for <a src="http://developers.box.com/">Box</a>
 
 @see ICPLoginProvideer
 */
@interface ICPBoxLoginProvider : NSObject <ICPLoginProvider>

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPBoxLoginProvider is an implementation of ICPLoginProvider for <a src="http://developers.box.com/">Box</a>
 
 @param authType                ICPBoxLoginProviderAuthType used to authenticate the user
 @param accessTokenOperation    Block used to request the app to retrieve the user access token when using ICPBoxLoginProviderAuthTypeAPIKey
 @param delegate                Object that will be notified for each step of the authentication
 
 @see ICPBoxLoginProviderAuthType
 @see ICPLoginProvider
 
 @return An ICPBoxLoginProvider instance
 */
- (instancetype) initWithType:(ICPBoxLoginProviderAuthType)authType
         accessTokenOperation:(_Nullable ICPBoxLoginProviderAccessTokenOperation)accessTokenOperation
                  andDelegate:(_Nullable id<ICPLoginProviderDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
