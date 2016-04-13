//
//  ICPStation.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//
#import "ICPIndex.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The station
 */

@protocol ICPStation <NSObject>

/**
 *  The stationId
 */
@property (nonatomic, strong, readonly) NSString *stationId;

/**
 *  The stationId description
 */
@property (nonatomic, strong, readonly, nullable) NSString *desc;

/**
 *  The stationId index on Datacap server
 */
@property (nonatomic, assign, readonly) ICPIndex index;

@end

NS_ASSUME_NONNULL_END
