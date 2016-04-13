//
//  ICPCapture+Service.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPCapture.h"

NS_ASSUME_NONNULL_BEGIN

@interface ICPCapture (Service)

- (nullable ICPSessionManager*)sessionManagerForService:(id<ICPService>)service withCredential:(NSURLCredential *)credential;

@end

NS_ASSUME_NONNULL_END
