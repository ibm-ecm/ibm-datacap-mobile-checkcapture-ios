//
//  ICPBatchType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPObjectType.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPDatacapService
, ICPDocumentType;

/** A protocol that represents the batch type. */
@protocol ICPBatchType <ICPObjectType>

/** The service from which this profile was created */
@property (nonatomic, strong, nullable, readonly) id<ICPDatacapService> relatedDatacapService;

/** An array of documentTypes avalible for this batch type. */
@property (nonatomic, strong) NSArray<id<ICPDocumentType> > *documentTypes;

@end

NS_ASSUME_NONNULL_END
