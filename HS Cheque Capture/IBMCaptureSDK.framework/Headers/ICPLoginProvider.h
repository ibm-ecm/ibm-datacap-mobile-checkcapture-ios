//
//  ICPSessionManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPLoginProvider;

/**
 The ICPLoginProviderDelegate is the protocol that an ICPLoginProvider uses to notify an object
 about the login and logout steps.
 
 @see ICPLoginProvider
 */
@protocol ICPLoginProviderDelegate <NSObject>

/**
 For some services, the provider has to present a third party screen to handle the user authentication.
 This method is called to notify the application that this screen will be presented
 
 @param loginProvider   The ICPLoginProvider that is performing the operation
 
 @return    A flag indicating if the provider is allowed to present the login screen
 */
- (BOOL)loginProviderWillPresentThirdPartyLoginScreen:(id<ICPLoginProvider>)loginProvider;

@optional

/**
 This method is called if the perform login operation fails.
 
 @param loginProvider   The ICPLoginProvider that is performing the operation
 @param error           The error that invalidated the authentication
 */
- (void)loginProvider:(id<ICPLoginProvider>)loginProvider didFailToAuthenticateUserWithError:(NSError *)error;

/**
 This method is called when the user is authenticated with success
 
 @param loginProvider   The ICPLoginProvider that is performing the operation
 */
- (void)loginProviderDidAuthenticateUser:(id<ICPLoginProvider>)loginProvider;

/**
 This method is called when the user session is finished
 
 @param loginProvider   The ICPLoginProvider that is performing the operation
 */
- (void)loginProviderDidLogoutUser:(id<ICPLoginProvider>)loginProvider;

@end

/**
 This block is used to report the caller when an login or logout operation is finished.
 
 @param success Flag to indicate if the operation succeed or not
 @param error   If the operation fails, this will be the error that caused it.
 */
typedef void(^ICPLoginProviderCompletionBlock)(BOOL success, NSError * _Nullable error);


@protocol ICPLoginProvider <NSObject>

/** 
 Object that is used to notify the application about the login and logout steps
 
 @see ICPLoginProviderDelegate
 */
@property (nonatomic, weak, nullable) id<ICPLoginProviderDelegate> delegate;
/** This NSDictionary holds any aditional header that need to be passed to authenticate HTTP requests */
@property (readonly, nullable) NSDictionary *headers;

/**
 This method will authenticate the user in the service
 
 @param completion  Block that is called once the authentication is finished
 */
- (void)performLogin:(_Nullable ICPLoginProviderCompletionBlock)completion;

/**
 This method will logout the user from the service and remove the local cache files
 
 @param completion  Block that is called once the session is closed
 */
- (void)performLogout:(_Nullable ICPLoginProviderCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
