//
//  ICPSessionManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPConfigurationProvider, ICPBatch, ICPStorageProvider, ICPRemoteComputationProvider,
ICPSetupDCO, ICPLoginProvider, ICPObjectFactory, ICPRemoteOperationsManager, ICPBatchType;
@class ICPRemoteComputationManager;

typedef void(^ICPSessionManagerBatchTypeDownloadBlock)(BOOL success, id<ICPBatchType> _Nullable batchType, NSError * _Nullable error);
typedef void(^ICPSessionManagerUpdateProgess)(float progess, id _Nullable currentObject);
typedef void(^ICPSessionManagerUploadCompletion)(BOOL success, _Nullable id<ICPBatch> batch, NSError * _Nullable error);
typedef void(^ICPSessionManagerSetupDCODownloadBlock)(BOOL success, NSArray<id<ICPSetupDCO>> *setupList, NSError * _Nullable error);

/**
 The ICPSessionManager is responsable for communicating with the servers to upload/download files
 */
@interface ICPSessionManager : NSObject

/** NSURL of the configurated server */
@property (nonatomic, strong, nullable, readonly) NSURL *baseURL;

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPSessionManager is responsable for communicating with the servers to upload/download files
 
 @param objectFactory           Application's ICPObjectFactory
 @param loginProvider           ICPLoginProvider used to authenticate in the server
 @param configurationProvider   ICPConfigurationProvider that will retrieve the configurations from the server
 @param storageProvider         ICPStorageProvider that will upload/download files from the server
 
 @see ICPObjectFactory
 @see ICPLoginProvider
 @see ICPConfigurationProvider
 @see ICPStorageProvider
 
 @return An ICPSessionManager instance
 */
- (instancetype) initWithObjectFactory:(id<ICPObjectFactory>)objectFactory
                         loginProvider:(id<ICPLoginProvider>)loginProvider
                 configurationProvider:(id<ICPConfigurationProvider>)configurationProvider
                    andStorageProvider:(id<ICPStorageProvider>)storageProvider NS_DESIGNATED_INITIALIZER;

/**
 This method is responsable to check and upload a ICPBatch to the server
 
 @param batch       ICPBatch that will be uploaded to the server
 @param progress    Block that will be called to show the upload progress
 @param completion  Block that will be called once the operation is completed
 */
- (void) uploadBatch:(id<ICPBatch>)batch
   withProgressBlock:(_Nullable ICPSessionManagerUpdateProgess)progress
       andCompletion:(_Nullable ICPSessionManagerUploadCompletion)completion;

/**
 This method is responsable for downloading the ICPBatchType related to a ICPSetupDCO
 
 @param setupDCO    ICPSetupDCO object with the configuration that will be downloaded
 @param completion  Block that will be called once the operation is completed
 */
- (void) downloadBatchTypeWithSetup:(id<ICPSetupDCO>)setupDCO
                      andCompletion:(ICPSessionManagerBatchTypeDownloadBlock)completion;

/**
 This method is responsable for downloading the list of available ICPSetupDCO list
 
 @param completion  Block that will be called once the operation is completed
 */
- (void) downloadSetupDCOListWithCompletion:(ICPSessionManagerSetupDCODownloadBlock)completion;

/**
 This method creates and configure an ICPRemoteComputationManager for the same server of the ICPSessionManager
 
 @param provider ICPRemoteComputationProvider used to configurate the manager
 
 @see ICPRemoteComputationManager
 
 @return An ICPRemoteComputationManager instance, configurated to the same server of the ICPSessionManager
 */
- (ICPRemoteComputationManager *)remoteComputationManagerWithProvider:(id<ICPRemoteComputationProvider>)provider;

@end

NS_ASSUME_NONNULL_END
