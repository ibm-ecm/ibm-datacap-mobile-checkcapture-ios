//
//  ICPPersistentObjectFactory.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <CoreData/CoreData.h>

#import "ICPObjectFactory.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The ICPPersistentObjectFactory manages the lifecycle of persistent ICPObjects. It augments the ICPObjectFactory with a number
 of methods which
 enable persistent operations.

 Note that changes made to objects managed by an ICPPersistentObjectFactory are not saved to the persistent store until the
 ```save``` method is called.
 @see ICPCapture
 @see ICPObjectFactory
 */
@protocol ICPPersistentObjectFactory <ICPObjectFactory>

/**
 *  Get stored objects conforming to the given protocol.
 *
 *  @param protocol protocol Fetch objects conforming to this protocol.
 *
 *  @return The stored objects.
 */
- (NSArray *)fetchAllProtocolObjects:(Protocol *)protocol;

/**
 Delete the given object from the persistent store.

 @param object The object to delete from the persistent store.
 */
- (void)deleteObject:(id)object;

/**
 Save new objects, updated objects and deleted objects to the persistent store.
 */
- (void)save;

/**
 *  Discard unsaved changes
 */
- (void)rollback;

/**
 *  Creates a fetched results controller for batches with status specified
 *
 *  @param statuses An array of ICPStatus as NSNumber, e.g. @[@(ICPStatusUploading), @(ICPStatusUploaded)]
 *
 *  @return The fetched results controller
 */
-(NSFetchedResultsController *)fetchResultsControllerForBatchesWithStatuses:(NSArray <NSNumber *>*)statuses;

@end

NS_ASSUME_NONNULL_END
