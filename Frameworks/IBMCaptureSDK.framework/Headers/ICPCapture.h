//
//  ICPCapture.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPObjectFactory , ICPServiceClient, ICPService, ICPOcrEngine, ICPImageEngine,
ICPBarcodeEngine, ICPTransactionClient;

@class ICPSessionManager;

/**
 *  The ICPCaptureObjectFactoryType is used to specify the persistence mode to be used for objects created by the
 * ICPObjectFactory
 */
typedef NS_ENUM(NSUInteger, ICPCaptureObjectFactoryType) {
    /** Objects are not saved on the device storage. */
    ICPCaptureObjectFactoryTypeNonPersistent = 0,
    /** Objects are stored on device. */
    ICPCaptureObjectFactoryTypePersistent,
    /** Counter property for enum. */
    ICPCaptureObjectFactoryTypeCount
};

/**
 The ICPCapture class is the entry point into the IBMCapture SDK. Responsibilities of this class include creation of an
 ICPObjectFactory for persistence and an ICPServiceClient for networking
*/
@interface ICPCapture : NSObject

/**
 *  The ICPObjectFactory for this ICPCapture instance. The ICPObjectFactory is responsible for object lifecycle management and
 * persistence.
 */
@property (nonatomic, strong, readonly, nullable) id<ICPObjectFactory> objectFactory;

/**
 Create an instance of the ICPCapture class with an objectFactoryType, used to control object persistence.

 @param objectFactoryType The type of object factory to use.
 @return An instance of the ICPCapture class.
 */
+ (nullable instancetype)instanceWithObjectFactoryType:(ICPCaptureObjectFactoryType)objectFactoryType;


@end

NS_ASSUME_NONNULL_END
