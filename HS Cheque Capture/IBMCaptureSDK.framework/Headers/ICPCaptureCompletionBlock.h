
//
//  ICPCaptureCompletionBlock.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

/**
 A default completion block.

 This block is commonly executed after completion of a network task.
 */
typedef void (^ICPCaptureCompletionBlock)(BOOL success, id _Nullable result, NSError *_Nullable error);

NS_ASSUME_NONNULL_END
