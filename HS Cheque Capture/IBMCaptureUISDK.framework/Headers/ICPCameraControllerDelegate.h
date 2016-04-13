//
//  ICPCameraControllerDelegate.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol ICPPage;

/**
 *  The ICPCameraControllerDelegate is used to be notified about events happening in the camera controller
 */
@protocol ICPCameraControllerDelegate <NSObject>

@optional

/**
 Notify delegate that a user tapped on a page in the camera roll view
 @param cameraController The Camera Controller
 @param page ICPPage selected in camera roll view.
 */
- (void)cameraController:(nullable ICPCameraController *)cameraController didSelectPage:(id<ICPPage>)page;

/**
 Notify delegate that a took a photo or imported one and an ICPPage was created
 @param cameraController The Camera Controller
 @param page ICPPage selected in camera roll view.
 */
- (void)cameraController:(nullable ICPCameraController *)cameraController didCreatePage:(id<ICPPage>)page;

/**
 Notify delegate that the gallery button in the Camera Controller has been tapped and the controller expects an image in
 return
 @param cameraController The Camera Controller
 @param rect The frame of the gallery button, usually needed to display popover on iPad
 @param completionBlock A completion block returning an image for the page to be added to the Camera Controller. The
 completion block MUST be called with image nil if operation is cancelled, else auto document scanning will not resume.
 */
- (void)cameraController:(nullable ICPCameraController *)cameraController
    didSelectImportImageFromRect:(CGRect)rect
             withCompletionBlock:(ICPCameraControllerImagePickedBlocked)completionBlock;

/**
 Notify delegate that position of the gallery button in the camera controller has changed. This is generally used to update
 the position of a popover after a rotation event.
 @param cameraController The Camera Controller
 @param frame The Gallery Button frame
 */
- (void)cameraController:(ICPCameraController *)cameraController galleryButtonFrameDidChange:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
