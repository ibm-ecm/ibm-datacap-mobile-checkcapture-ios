//
//  ICPDCOManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPSetupDCO;
@protocol ICPBatchType;

/**
 This block is used as completion of the asynchronous operation of downloading the list of
 possible dco configurations.
 
 @param success Flag to indicate if the operation succeed or not
 @param dcoList The list of ICPSetupDCO available in the server
 @param error   The error that invalidated the operation
 
 @see ICPSetupDCO
 */
typedef void(^ICPConfigurationProviderList)(BOOL success, NSArray<id<ICPSetupDCO>> *dcoList, NSError * _Nullable error);

/**
 This block is used as completion of the asynchronous operation of downloading the configuration of
 a specif dco file.
 
 @param success Flag to indicate if the operation succeed or not
 @param dcoFile The ICPBatchType configurated with the information from the configuration file
 @param error   The error that invalidated the operation
 
 @see ICPBatchType
 */
typedef void(^ICPConfigurationProviderFile)(BOOL success, id<ICPBatchType> _Nullable dcoFile, NSError * _Nullable error);

/** This protocol declares the methods used to retrieve an application configuration file from the service */
@protocol ICPConfigurationProvider <NSObject>

/**
 *  Retrieve the list of DCO configuration files available
 *
 *  @param  completion The block that will be called once the operation is completed
 *
 *  @see    ICPConfigurationProviderList
 */
- (void) getDCOList:(ICPConfigurationProviderList)completion;

/**
 *  Retrieve the batch type associated to a configuration file
 *
 *  @param  configurationFile       The configuration file
 *  @param  completion              The block that will be called once the operation is completed
 *
 *  @see    ICPConfigurationProviderFile
 */
- (void) getConfigurationFile:(id<ICPSetupDCO>)configurationFile withCompletion:(ICPConfigurationProviderFile)completion;

@end

NS_ASSUME_NONNULL_END
