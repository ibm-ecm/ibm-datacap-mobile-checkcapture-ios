//
//  ICPService.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol ICPApplication, ICPSetupDCO;

typedef NS_ENUM(NSUInteger, ICPDatacapServiceProviderType) {
    ICPDatacapServiceProviderTypeUnknown = 0,
    ICPDatacapServiceProviderTypeDatacap = 1,
    ICPDatacapServiceProviderTypeBox = 2
};

/**
 *  The ICPService protocol represents a remote service.
 */
@protocol ICPService <NSObject>

/** The URL of the remote service. */
@property (nonatomic, strong, nullable) NSURL *baseURL;

@property (nonatomic, readonly) ICPDatacapServiceProviderType providerType;

/**
 *  The application
 */
@property (nonatomic, strong, nullable) id<ICPApplication> application;

/** 
 *  The name of the server where the services is hosted
 */
@property (nonatomic, strong, nullable) NSString *provider;

/**
 *  The setupDCO
 */
@property (nonatomic, strong, nullable) id<ICPSetupDCO> setupDCO;

@end

NS_ASSUME_NONNULL_END
