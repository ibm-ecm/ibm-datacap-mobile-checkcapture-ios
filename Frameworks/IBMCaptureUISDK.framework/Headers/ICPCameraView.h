//
//  ICPCameraPreview.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPCameraViewDelegate;

/**
 * The ICPCameraView is a simple interface to complex functionality, allowing preview, detection and capture of optimised
 * images from the device's camera. Try to keep the view aspect ratio to 4/3 else the camera image might be deformed to fit.
 */

IB_DESIGNABLE

@interface ICPCameraView : UIView

/** Enable automatic document detection */
@property (nonatomic, assign) IBInspectable BOOL automaticallyDetectDocuments;

/** Enable black and white filtering */
@property (nonatomic, assign) IBInspectable BOOL enableBlackAndWhiteFilter;

/** Enable the device torch if available */
@property (nonatomic, assign) IBInspectable BOOL enableTorch;

/** Only detect a document as valid if text is found. This feature is not available prior to iOS9 and does not work if the
 * text is too small or not in the same orientation as the device. */
@property (nonatomic, assign) BOOL detectDocumentsWithTextOnly;

/** Returns YES if flash light is on */
@property (nonatomic, assign) BOOL isFlashOn;

/** This is only used in Interface builder to set a placeholder image for Camera View detection preview */
@property (nonatomic, assign, nullable) IBInspectable UIImage *ibPlaceholderImage;

/** The delegate for this camera view */
@property (nonatomic, weak, nullable) id<ICPCameraViewDelegate> delegate;

/**
 *  This is the percentage of the view bounds that the largest side of the document must cover to be considered valid. This
 * value must be between 0 and 1.0
 */
@property (nonatomic, assign) CGFloat minimumScreenPercentage;

/**
 *  The miminum width/height aspect ratio the document must be to be considered valid. (e.g. credit card 1.4 - 1.8, A4 is 1.4,
 * letter 1.2, cheque 2.0)
 */
@property (nonatomic, assign) CGFloat minimumAspectRatio;

/**
 *  The maximum width/height aspect ratio the document must be to be considered valid. (e.g. credit card 1.4 - 1.8, A4 is 1.4,
 * letter 1.2, cheque 2.0)
 */
@property (nonatomic, assign) CGFloat maximumAspectRatio;

/**
 *  The maximum acceleration of the motion sensor allowed before the shot is considered invalid. If acceleration goes above
 * that, the camera view won't try to capture. Default value is 0.1;
 */
@property (nonatomic, assign) CGFloat accelerationThreshold;

/** Take a photo */
- (void)takePhoto;

/** Stops the camera preview video session */
- (void)stopPreview;

/** Restart the camera preview video session */
- (void)restartPreview;

@end

NS_ASSUME_NONNULL_END