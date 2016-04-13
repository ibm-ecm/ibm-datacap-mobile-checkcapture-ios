//
//  ICPObjectFactory.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPIndex.h"
#import "ICPRect.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPService,
ICPDatacapService, ICPBatch, ICPDocument, ICPPage, ICPField, ICPBatchType, ICPDocumentType,
ICPPageType, ICPFieldType, ICPObject, ICPObjectType, ICPCharacter, ICPCharacter, ICPApplication, ICPWorkflow, ICPJob,
ICPStation, ICPSetupDCO;

/**
 The ICPObjectFactory manages the lifecycle of ICPObjects, depending on the configuration of the object factory.

 ICPObjectFactory supports two types of managed objects: ICPCaptureObjectFactoryTypeNonPersistent and
 ICPCaptureObjectFactoryTypePersistent.

 ICPCaptureObjectFactoryTypeNonPersistent does not persist to disk once an app leaves
 memory, which is useful when data security is of high importance, or when users are required to complete tasks before leaving
 the app.

 ICPCaptureObjectFactoryTypePersistent creates a factory implementing the ICPPersistentObjectFactory protocol. This will cause
 all objects to be stored on disk until they are explicitly removed, such as when objects are uploaded.

 @see ICPCapture
 @see ICPPersistentObjectFactory
 */
@protocol ICPObjectFactory <NSObject>

/**
 Creates an ICPBoxService.
 @param application Application that created the service
 @return A managed object which conforms to the ICPDataService protocol.
 */
- (id<ICPDatacapService>)boxServiceWithApplication:(id<ICPApplication>)application;

/**
 Creates an ICPDatacapService.
 @param baseURL     The base URL for the service.
 @return A managed object which conforms to the ICPDataService protocol.
 */
- (id<ICPDatacapService>)datacapServiceWithBaseURL:(NSURL *)baseURL;

/**
 *  Creates an ICPBatchType
 *
 *  @param typeId         The identifier for the batch
 *  @param datacapService The Datacap Service it corresponds to
 *
 *  @return A managed object which conforms to the ICPBatchType protocol.
 */
- (id<ICPBatchType>)batchTypeWithTypeId:(NSString *)typeId inDatacapService:(nullable id<ICPDatacapService>)datacapService;

/**
 Creates an ICPBatch with status set to ICPStatusTemp
 @return A managed object which conforms to the ICPBatch protocol.
 */
- (id<ICPBatch>)batchWithDatacapService:(nullable id<ICPDatacapService>)datacapService type:(nullable id<ICPBatchType>)batchType;

/**
 Creates an ICPDocument.
 @return A managed object which conforms to the ICPDocument protocol.
 */
- (id<ICPDocument>)documentWithBatch:(nullable id<ICPBatch>)batch type:(id<ICPDocumentType>)documentType;

/**
 Creates an ICPPage.
 @return A managed object which conforms to the ICPPage protocol.
 */
- (id<ICPPage>)pageWithDocument:(nullable id<ICPDocument>)document type:(nullable id<ICPPageType>)pageType;

/**
 Creates an ICPField.
 @return A managed object which conforms to the ICPField protocol or nil if fieldType status = -1 and therefore field shoud be ignored
 */
- (nullable id<ICPField>)fieldWithObject:(nullable id<ICPObject>)object type:(id<ICPFieldType>)fieldType;

/**
 Creates an ICPCharacter.
 @return A managed object which conforms to the ICPCharacter protocol.
 */

/**
 *  Creates an ICPCharacter.
 *
 *  @param characterString The character string. Length must be 1
 *  @param confidence      The confidence comprised between 0 and 1
 *  @param frame           The position of the recognized character
 *
 *  @return ICPCharacter
 */
- (id<ICPCharacter>)characterWithString:(NSString *)characterString confidence:(double)confidence andPosition:(ICPRect)frame;



/**
 Creates an ICPDocumentType.
 @return A managed object which conforms to the ICPDocumentType protocol.
 */
- (id<ICPDocumentType>)documentTypeWithTypeId:(NSString *)typeId;

/**
 Creates an ICPPageType.
 @return A managed object which conforms to the ICPPageType protocol.
 */
- (id<ICPPageType>)pageTypeWithTypeId:(NSString *)typeId;

/**
 Creates an ICPFieldType.
 @return A managed object which conforms to the ICPFieldType protocol.
 */
- (id<ICPFieldType>)fieldTypeWithTypeId:(NSString *)typeId;

/**
 *  Use this method to change the object type of an object. It will reset its properties and create appropriate ones.
 *
 *  @param objectType The object type
 *  @param object     The object
 */
- (void)setObjectType:(nullable id<ICPObjectType>)objectType forObject:(id<ICPObject>)object;

/**
 *  Create an application. This method is normally used only for testing as the ICPApplication should be retrieved from the
 * server to be used with a ICPDatacapService.
 *
 *  @param name The application name
 *
 *  @return The ICPApplication
 */
- (id<ICPApplication>)applicationWithName:(NSString *)name;

/**
 *  Create a workflow. This method is normally used only for testing as the ICPWorkflow should be retrieved from the server to
 * be used with a ICPDatacapService.
 *
 *  @param workflowId The workflowId
 *  @param index      The workflow index
 *
 *  @return the ICPWorkflow
 */
- (id<ICPWorkflow>)workflowWithWorkflowId:(NSString *)workflowId andIndex:(ICPIndex)index;

/**
 *  Create a job. This method is normally used only for testing as the ICPJob should be retrieved from the server to be used
 * with a ICPDatacapService.
 *
 *  @param jobId the jobId
 *  @param index the job index
 *
 *  @return the ICPJob
 */
- (id<ICPJob>)jobWithJobId:(NSString *)jobId andIndex:(ICPIndex)index;

/**
 *  Create a station. This method is normally used only for testing as the ICPStation should be retrieved from the server to
 * be used with a ICPDatacapService.
 *
 *  @param stationId   the stationId
 *  @param index       the station index
 *  @param description the station description
 *
 *  @return the ICPStation
 */
- (id<ICPStation>)stationWithStationId:(NSString *)stationId
                              andIndex:(ICPIndex)index
                        andDescription:(nullable NSString *)description;


/**
 *  Create a setupDCO. This method is normally used only for testing as the ICPSetupDCO should be retrieved from the server to
 * be used with a ICPDatacapService.
 *
 *  @param name the setupDCO name
 *
 *  @return the ICPSetupDCO
 */
- (id<ICPSetupDCO>)setupDCOWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
