//
//  ICPDatacapRemoteOperationsProvider.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPRemoteComputationProvider.h"
#import "ICPTransactionFileListMode.h"

NS_ASSUME_NONNULL_BEGIN

@class IBMDatacap;
@class ICPStorageHelper;
@protocol ICPTransactionFile;
@protocol ICPObjectFactory;
@protocol ICPLoginProvider;
@protocol ICPDatacapService;

typedef void(^ICPRemoteComputationTransactionCompletionBlock)(NSString * transactionId, BOOL success, id _Nullable result, NSError * _Nullable error);
typedef void(^ICPRemoteComputationStartTransactionCompletionBlock)(NSString * _Nullable transactionId, NSError * _Nullable error);
typedef void(^ICPRemoteComputationGetTransactionFilesCompletionBlock)(NSString * transactionId, NSArray<id<ICPTransactionFile>> *files, NSError * _Nullable error);

/**
 ICPDatacapRemoteComputationProvider is an implementation of ICPRemoteComputationProvider that
 enables and handle page transactions on the Datacap server
 
 @see ICPRemoteComputationProvider
 */
@interface ICPDatacapRemoteComputationProvider : NSObject <ICPRemoteComputationProvider>

@property (nonatomic, strong) NSString *transactionApplication;

- (instancetype)init NS_UNAVAILABLE;

/**
 ICPDatacapRemoteComputationProvider is an implementation of ICPRemoteComputationProvider that
 enables and handle page transactions on the Datacap server
 
 @param datacap         IBMDatacap that will handle the requests to the datacap server
 @param service         ICPDatacapService with the server configuration
 @param storageHelper   ICPStorageHelper used to load files from the disk
 @param objectFactory   Application's ICPObjectFactory
 
 @return An ICPDatacapRemoteComputationProvider instance
 */
- (instancetype)initWithDatacap:(IBMDatacap *)datacap
                        service:(id<ICPDatacapService>)service
                  storageHelper:(ICPStorageHelper *)storageHelper
               andObjectFactory:(id<ICPObjectFactory>)objectFactory NS_DESIGNATED_INITIALIZER;

#pragma mark - Datacap transaction server

/**
 *  Start a transaction on the server
 *
 *  @param completionBlock The completion block. If successful the transactionId is returned as an NSString
 */
- (NSOperation *)startTransactionWithCompletionBlock:(ICPRemoteComputationStartTransactionCompletionBlock)completionBlock;

/**
 *  Upload a file to the current transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param path             Path to the file on the local filesystem
 *  @param completionBlock  The completion block
 */
- (NSOperation *)setTransaction:(NSString *)transactionId
                           file:(NSString *)filePath
            withCompletionBlock:(ICPRemoteComputationTransactionCompletionBlock)completionBlock;

/**
 *  Executes rules against uploaded files for the transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param rulesets         Coma delimited list of rulesets
 *  @param pageFileName     Page file name, e.g. MBatch.xml.
 *  @param timeout          Timeout for the operation
 *  @param completionBlock  The completion block
 */
- (NSOperation *)executeTransaction:(NSString *)transactionId
                           rulesets:(NSString *)rulesets
                       pageFileName:(NSString *)pageFileName
                            timeout:(NSUInteger)timeout
                withCompletionBlock:(ICPRemoteComputationTransactionCompletionBlock)completionBlock;

/**
 *  Gets a list of files for the current transaction.
 *
 *  @param transactionId    Id of the transaction
 *  @param mode             File wanted
 *  @param completionBlock  The completion block
 */
- (NSOperation *)getTransaction:(NSString *)transactionId
               fileListWithMode:(ICPTransactionFileListMode)mode
             andCompletionBlock:(ICPRemoteComputationGetTransactionFilesCompletionBlock)completionBlock;

/**
 *  Get a file for the current transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param fileName         File name
 *  @param completionBlock  The completion block
 */
- (NSOperation *)getTransaction:(NSString *)transactionId
                           file:(NSString *)fileName
            withCompletionBlock:(ICPRemoteComputationTransactionCompletionBlock)completionBlock;

/**
 *  End the existing transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param completionBlock  The completion block
 */
- (NSOperation*)endTransaction:(NSString *)transactionId
           withCompletionBlock:(ICPRemoteComputationTransactionCompletionBlock)completionBlock;

NS_ASSUME_NONNULL_END

@end
