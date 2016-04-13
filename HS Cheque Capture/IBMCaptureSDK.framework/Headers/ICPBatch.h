//
//  ICPBatch.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPDocument, ICPDatacapService, ICPDocumentType;

/**
 The ICPBatch protocol contains a number of documents.
 It extends ICPObject so it may also contain fields and has a type.
 @see ICPObject

 An ICPBatch instance can be uploaded to a specified remote service using the ICPServiceClient object.
 @see ICPServiceClient -uploadBatch:progressBlock:completionBlock.
 */
@protocol ICPBatch <ICPObject>

/** A reference id for the batch once it has been uploaded to a remote service. */
@property (nonatomic, strong, nullable, readonly) NSString *remoteId;

/** The status of the ICPBatch on the remote service. For example: "Processing". */
@property (nonatomic, strong, nullable, readonly) NSString *remoteStatus;

/** A date representing the date and time the batch was created by the SDK. */
@property (nonatomic, strong, readonly) NSDate *creationDate;

/** The service from which this profile was created */
@property (nonatomic, strong, nullable, readonly) id<ICPDatacapService> relatedDatacapService;

/** An NSArray containing documents inside the batch. */
@property (nonatomic, strong) NSArray<id<ICPDocument> > *documents;

/** An NSError object that expose the last upload attempt failure reason **/
@property (nonatomic, strong, nullable, readonly) NSError *lastUploadError;

- (id<ICPDocument>)createNewDocumentWithType:(id<ICPDocumentType>)type;

/**
 Adds a document to the batch.
 @param document The document to add to the batch.
 */
- (void)addDocument:(id<ICPDocument>)document;

/**
 Removes a document from the batch.
 @param document The document to remove from the batch.
 */
- (void)removeDocument:(id<ICPDocument>)document;

/**
 Reorders documents in the document.
 @param atIndex The index from where thedocumentdocument should be moved.
 @param toIndex The index to where the page should be moved.
 */
- (void)moveDocumentAtIndex:(NSUInteger)atIndex toIndex:(NSUInteger)toIndex;

/**
 Inserts a document at the given index.
 @param document The document to be inserted.
 @param index The index where the document should be inserted.
 */
- (void)insertDocument:(id<ICPDocument>)page atIndex:(NSUInteger)index;

- (void)enqueueBatch;

- (void)markAsSaved;

- (void)markAsIncomplete;

@end

NS_ASSUME_NONNULL_END
