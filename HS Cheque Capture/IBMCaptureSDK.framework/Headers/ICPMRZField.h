//
//  ICPMRZField.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ICPMRZField : NSObject

@property (nonatomic, assign, readonly) BOOL checked;
@property (nonatomic, strong, readonly) NSNumber *confidence;
@property (nonatomic, strong, readonly) NSString *value;

+ (instancetype)empty;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithValue:(NSString *)value
                   confidence:(NSNumber *)confidence
                      checked:(BOOL)checked NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
