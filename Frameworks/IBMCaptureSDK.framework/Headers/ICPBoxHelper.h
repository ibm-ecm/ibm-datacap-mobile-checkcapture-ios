//
//  ICPBoxHelper.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPServerHelper.h"

@protocol ICPObjectFactory, ICPSetupDCO;

NS_ASSUME_NONNULL_BEGIN

typedef void(^ICPBoxHelperSetupDCO)(BOOL success, id<ICPApplication> application, id<ICPSetupDCO> _Nullable setup, NSError *error);

@interface ICPBoxHelper : NSObject <ICPServerHelper>

- (instancetype) init NS_UNAVAILABLE;
- (instancetype) initWithObjectFactory:(id<ICPObjectFactory>)objectFactory;

- (void) setupDCOForApplication:(id<ICPApplication>)application withCompletionBlock:(ICPBoxHelperSetupDCO)completion;

@end

NS_ASSUME_NONNULL_END
