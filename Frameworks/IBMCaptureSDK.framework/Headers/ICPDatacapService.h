//
//  ICPDatacapService.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <IBMCaptureSDK/ICPService.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPWorkflow, ICPStation, ICPJob, ICPSetupDCO, ICPBatchType, ICPBatch;

/**
 The ICPDatacapService protcol contains the information required to connect to a remote IBM Datacap application.
 It is used by the ICPServiceClient and the ICPDatacapHelper.

 @see ICPServiceClient
 @see ICPDatacapHelper
 */
@protocol ICPDatacapService <ICPService>

/** Allow invalid certificates. This is usually used in development mode where the certificate is self-signed, else connection
 * will be refused */
@property (nonatomic, assign) BOOL allowInvalidCertificates;

/** The username for the remote service */
@property (nonatomic, strong) NSString *username;

/**
 *  The workflow
 */
@property (nonatomic, strong, nullable) id<ICPWorkflow> workflow;

/**
 *  The job
 */
@property (nonatomic, strong, nullable) id<ICPJob> job;

/**
 *  The station
 */
@property (nonatomic, strong, nullable) id<ICPStation> station;

/**
 *  The batch types supported by the service
 */
@property (nonatomic, strong) NSArray<id<ICPBatchType> > *batchTypes;

/**
 *  The batches associated with the service
 */
@property (nonatomic, strong) NSArray<id<ICPBatch> > *batches;

/**
 Adds a batch type to the service.
 @param batchType the batch type to be added to the service.
 */
- (void)addBatchType:(id<ICPBatchType>)batchType;

/**
 Removes a batch type from the service.
 @param batchType the batch type to be removed from the service.
 */
- (void)removeBatchType:(id<ICPBatchType>)batchType;

/**
 Adds a batch to the service.
 @param batch The batch to add to the service.
 */
- (void)addBatch:(id<ICPBatch>)batch;

/**
 Removes a batch from the service.
 @param batch The batch to remove from the service.
 */
- (void)removeBatch:(id<ICPBatch>)batch;

/**
 Reorders batches in the document.
 @param atIndex The index from where the batch should be moved.
 @param toIndex The index to where the batch should be moved.
 */
- (void)moveBatchAtIndex:(NSUInteger)atIndex toIndex:(NSUInteger)toIndex;

/**
 Inserts a batch at the given index.
 @param batch The batch to be inserted.
 @param index The index where the batch should be inserted.
 */
- (void)insertBatch:(id<ICPBatch>)batch atIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
