//
//  ICPBoxConfigurationProvider.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPConfigurationProvider.h"

@protocol ICPLoginProvider, ICPObjectFactory, ICPConfigurationParser;
@class ICPBoxSDKHelper;

NS_ASSUME_NONNULL_BEGIN

/**
 The ICPBoxConfigurationProvider is an implementation of ICPConfigurationProvider responsable for 
 retrieving the configuration files from the Box's path structure.
 
 The provider will consider that all the folders on /DatacapApplications are valid applications name.
 Inside the application folder, will be expected to have a valid configuration file, 
 ending with the path structure:
 
 <i>/DatacapApplications/Application/dco.xml</i>
 
 The default configuration file name is <b>dco.xml</b>, 
 but it can be changed using a ICPConfigurationParser and providing the correct configuration file name
 */
@interface ICPBoxConfigurationProvider : NSObject <ICPConfigurationProvider>

- (instancetype)init NS_UNAVAILABLE;

/**
 The ICPBoxConfigurationProvider is an implementation of ICPConfigurationProvider responsable for
 retrieving the configuration files from the Box's path structure.
 
 @param loginProvider   ICPLoginProvider used to authenticate in the BOX sdk
 @param objectFactory   Application's ICPObjectFactory
 @param helper          ICPBoxSDKHelper used to access BOX sdk operations
 
 @see ICPObjectFactory
 @sse ICPLoginProvider
 @see ICPBoxSDKHelper
 
 @return An ICPBoxConfigurationProvider instance
 */
- (instancetype)initWithLoginProvider:(id<ICPLoginProvider>)loginProvider
                        objectFactory:(id<ICPObjectFactory>)objectFactory
                            andHelper:(ICPBoxSDKHelper *)helper;

/**
 The ICPBoxConfigurationProvider is an implementation of ICPConfigurationProvider responsable for
 retrieving the configuration files from the Box's path structure.
 
 @param loginProvider       ICPLoginProvider used to authenticate in the BOX sdk
 @param parser              ICPConfigurationParser used to parse the configuration file download from the server into a ICPSetupDCO object
 @param objectFactory       Application's ICPObjectFactory
 @param helper              ICPBoxSDKHelper used to access BOX sdk operations
 @param configurationFile   The name of the configuration in the application folder
 
 @see ICPObjectFactory
 @sse ICPLoginProvider
 @see ICPBoxSDKHelper
 @see ICPSetupDCO
 
 @return An ICPBoxConfigurationProvider instance
 */
- (instancetype)initWithLoginProvider:(id<ICPLoginProvider>)loginProvider
                           dataParser:(id<ICPConfigurationParser>)parser
                               helper:(ICPBoxSDKHelper *)helper
             andConfigurationFileName:(NSString *)configurationFile NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
