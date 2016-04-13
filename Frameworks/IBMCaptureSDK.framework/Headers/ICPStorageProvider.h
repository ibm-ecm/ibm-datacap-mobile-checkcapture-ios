//
//  ICPStorageManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPPage,
ICPBatch,
ICPDocument;

typedef void(^ICPStorageProviderOperationCompletionBlock)(BOOL success, NSError * _Nullable error);
typedef void(^ICPStorageProviderUploadCompletionBlock)(BOOL success, _Nullable id<ICPBatch> batch, NSError * _Nullable error);
typedef void(^ICPStorageProviderDownloadBatchCompletionBlock)(BOOL success, NSData * _Nullable batchFile, NSError * _Nullable error);
typedef void(^ICPStorageProviderDownloadPageCompletionBlock)(BOOL success, NSData * _Nullable pageFile, NSError * _Nullable error);
typedef void(^ICPStorageProviderDownloadFileCompletionBlock)(BOOL success, NSData * _Nullable file, NSError * _Nullable error);
typedef void(^ICPStorageProviderDownloadBatchListCompletionBlock)(BOOL success, NSArray<id<ICPBatch>> *batches, NSError * _Nullable error);
typedef void(^ICPStorageProviderProgressBlock)(float progress, id _Nullable uploadingObject);

/**
 This ICPStorageProvider is responsable for the upload, download and delete of the ICPBatch objects in the remote server
 
 @see ICPBatch
 */
@protocol ICPStorageProvider <NSObject>

/**
 This method is used to upload a batch to the server. 
 If the batch status is ICPStatusUploaded or ICPStatusUploading, the operation will not be executed
 
 @param batch       ICPBatch that will be uploaded to the server
 @param progress    Block that will be used to show the upload progress
 @param completion  Block that will be called once the operation is finished
 
 @see ICPBatch
 @see ICPStatus
 */
- (void)uploadBatch:(id<ICPBatch>)batch
  withProgressBlock:(_Nullable ICPStorageProviderProgressBlock)progress
      andCompletion:(_Nullable ICPStorageProviderUploadCompletionBlock)completion;

/**
 This method will look for a file that represents a specific batch and delete it.
 
 @param batch       ICPBatch that represents the file that will be deleted
 @param completion  Block that will be called once the operation is finished
 
 @see ICPBatch
 */
- (void)deleteBatch:(id<ICPBatch>)batch
     withCompletion:(_Nullable ICPStorageProviderOperationCompletionBlock)completion;

/**
 This method will download the ICPBatch representation file from the server
 
 @param batch       ICPBatch that represents the file that will be downloaded
 @param completion  Block that will be called once the operation is finished
 
 @see ICPBatch
 */
- (void)downloadBatchFile:(id<ICPBatch>)batch
           withCompletion:(ICPStorageProviderDownloadBatchCompletionBlock)completion;

/**
 This method will download the page image storaged on the server
 
 @param pageName    Name of the page
 @param document    ICPDocument which the page is associated
 @param batch       ICPBatch wich the page is associated
 @param completion  Block that will be called once the operations is finished
 */
- (void)downloadPageFile:(NSString *)pageName
            fromDocument:(id<ICPDocument>)document
                andBatch:(id<ICPBatch>)batch
          withCompletion:(ICPStorageProviderDownloadPageCompletionBlock)completion;

/**
 This method will download any file associated to a batch
 
 @param fileName        The name of the file
 @param fileExtension   The extension of the file
 @param batch           ICPBatch which the file is associated
 @param completion      Block that will be called once the operation is finished
 */
- (void)downloadFileWithName:(NSString *)fileName
               fileExtension:(NSString *)fileExtension
                       batch:(id<ICPBatch>)batch
               andCompletion:(ICPStorageProviderDownloadFileCompletionBlock)completion;

/**
 This method locks a specific ICPBatch so no other user is able to edit it.
 
 @param batch       ICPBatch that will be locked
 @param completion  Block that will be called once the operation is finished
 */
- (void)lockBatch:(id<ICPBatch>)batch
   withCompletion:(_Nullable ICPStorageProviderOperationCompletionBlock)completion;

/**
 This method unlocks a specific ICPBatch, allowing other users to edit it.
 
 @param batch       ICPBatch that will be unlocked
 @param completion  Block that will be called once the operation is finished
 */
- (void)unlockBatch:(id<ICPBatch>)batch
     withCompletion:(_Nullable ICPStorageProviderOperationCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
