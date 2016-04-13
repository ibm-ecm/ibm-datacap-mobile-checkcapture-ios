//
//  ICPRemoteOperationsManager+Datacap.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "ICPRemoteComputationManager.h"
#import "ICPTransactionFileListMode.h"
#import "ICPTransactionFile.h"

NS_ASSUME_NONNULL_BEGIN

@interface ICPRemoteComputationManager (Datacap)

typedef void(^ICPRemoteOperationManagerTransactionCompletionBlock)(NSString * transactionId, BOOL success, id _Nullable result, NSError * _Nullable error);
typedef void(^ICPRemoteOperationManagerStartTransactionCompletionBlock)(NSString * _Nullable transactionId, NSError * _Nullable error);
typedef void(^ICPRemoteOperationManagerGetTransactionFilesCompletionBlock)(NSString * transactionId, NSArray<id<ICPTransactionFile>> *files, NSError * _Nullable error);

/**
 *  Start a transaction on the server
 *
 *  @param completionBlock The completion block. If successful the transactionId is returned as an NSString
 */
- (void)startTransactionWithCompletionBlock:(ICPRemoteOperationManagerStartTransactionCompletionBlock)completionBlock;

/**
 *  Upload a file to the current transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param path             Path to the file on the local filesystem
 *  @param completionBlock  The completion block
 */
- (void)setTransaction:(NSString *)transactionId
                  file:(NSString *)filePath
   withCompletionBlock:(ICPRemoteOperationManagerTransactionCompletionBlock)completionBlock;

/**
 *  Executes rules against uploaded files for the transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param rulesets         Coma delimited list of rulesets
 *  @param pageFileName     Page file name, e.g. MBatch.xml.
 *  @param completionBlock  The completion block
 */
- (void)executeTransaction:(NSString *)transactionId
                  rulesets:(NSString *)rulesets
              pageFileName:(NSString *)pageFileName
       withCompletionBlock:(ICPRemoteOperationManagerTransactionCompletionBlock)completionBlock;

/**
 *  Gets a list of files for the current transaction.
 *
 *  @param transactionId    Id of the transaction
 *  @param mode             File wanted
 *  @param completionBlock  The completion block
 */
- (void)getTransaction:(NSString *)transactionId
      fileListWithMode:(ICPTransactionFileListMode)mode
    andCompletionBlock:(ICPRemoteOperationManagerGetTransactionFilesCompletionBlock)completionBlock;

/**
 *  Get a file for the current transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param fileName         File name
 *  @param completionBlock  The completion block
 */
- (void)getTransaction:(NSString *)transactionId
                  file:(NSString *)fileName
   withCompletionBlock:(ICPRemoteOperationManagerTransactionCompletionBlock)completionBlock;

/**
 *  End the existing transaction
 *
 *  @param transactionId    Id of the transaction
 *  @param completionBlock  The completion block
 */
- (void)endTransaction:(NSString *)transactionId
   withCompletionBlock:(ICPRemoteOperationManagerTransactionCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
