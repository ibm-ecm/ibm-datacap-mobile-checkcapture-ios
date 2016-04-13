//
//  ICPCameraViewDelegate.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ICPCameraViewState.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The ICPCameraViewDelegate is used to get notified about events
 */
@protocol ICPCameraViewDelegate <NSObject>

/**
 *  This is the callback when a still photo has been captured
 *
 *  @param cameraView    The camera view
 *  @param originalPhoto The original photo
 *  @param modifiedPhoto The cropped photo if mode is automaticallyDetectDocuments is set to YES and document edges have been
 *detected
 */
- (void)cameraView:(ICPCameraView *)cameraView
    didTakeOriginalPhoto:(nullable UIImage *)originalPhoto
           modifiedPhoto:(nullable UIImage *)modifiedPhoto;

@optional
/**
 *  This method is called when a valid document has been detected. This can be used to tell the Camera View to take
 *the picture everytime a document is detected for example.
 *
 *  @param cameraView The Camera View
 */
- (void)cameraViewDidDetectDocument:(ICPCameraView *)cameraView;

/**
 *  The method is called to inform the delegate about the camera view validation
 *
 *  @param cameraView       The camera view
 *  @param validationStatus The validation result of the current image frame
 */
- (void)cameraView:(ICPCameraView *)cameraView didChangeState:(ICPCameraViewState)cameraState;

@end

NS_ASSUME_NONNULL_END
