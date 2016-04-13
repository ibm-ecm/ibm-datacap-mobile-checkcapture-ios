//
//  ICPImageEngine.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ICPFilterType.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  A completion block for edge detection
 *
 *  @param points returns an array of CGPoint contained as NSValue. In that order looking at image in orientation UP [topLeft,
 *topRight, bottomRight, bottomLeft]
 */
typedef void (^ICPImageEngineEdgePointsDetectedBlock)(NSArray<NSValue *> *_Nullable points);

/**
 *  A completion block for image processing
 *
 *  @param image The resulting image
 */
typedef void (^ICPImageEngineImageProcessedBlock)(UIImage *_Nullable image);

/**
 *  A completion block for image quality processing
 *
 *  @param quality returns a double between 0 and 1, 1 being good quality
 */
typedef void (^ICPImageEngineImageQualityProcessedBlock)(double quality);

/**
 The ICPImageEngine class provides image processing methods such as edge detection, deskew, cropping, filtering and rotation.
 This is an abstract class, and may be implemented using different underlying engines.

 All methods are dispatched onto the DISPATCH_QUEUE_PRIORITY_BACKGROUND queue, and call completion blocks on the main thread.

 The coordinate system of any points provided must match that of UIKit, with 0,0 being in the top left.

 @see ICPCapture -imageEngineWithProcessingLibrary
 */
@protocol ICPImageEngine <NSObject>

/**
 *  Performs edge detection for a given image.
 *
 *  @param image           The image
 *  @param completionBlock The completion block.
 */
- (void)detectEdgePointsInImage:(UIImage *)image completionBlock:(ICPImageEngineEdgePointsDetectedBlock)completionBlock;

/**
 *  Deskews a given image using a set of four points. Points should be in the order top left, top right, bottom right, bottom
 left.
 *
 *  @param points          An NSArray of CGPoints contained inside NSValue objects. In that order looking at image in
 orientation UP [topLeft, topRight, bottomRight, bottomLeft]
 *  @param image           The image.
 *  @param completionBlock The completion block.
 */
- (void)deskewRectWithPoints:(NSArray<NSValue *> *)points
                     inImage:(UIImage *)image
             completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

/**
 *  Attemtps to detect edges and deskews the image if edges are found
 *  @param image           The image.
 *  @param completionBlock The completion block.
 */
- (void)detectEdgesAndDeskewImage:(UIImage *)image completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

/**
 *  Performs cropping on the given image using a CGRect.
 *
 *  @param rect            rect The rect to crop.
 *  @param image           image The image.
 *  @param completionBlock The completion block.
 */
- (void)cropRect:(CGRect)rect inImage:(UIImage *)image completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

/**
 *  Applies a filter to the given image.
 *
 *  @param filter          The filter type.
 *  @param image           The image.
 *  @param completionBlock The completion block.
 *  @see ICPFilterType
 */
- (void)applyFilter:(ICPFilterType)filter
            toImage:(UIImage *)image
    completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

/**
 *  Rotates the given image 90 degrees to the right
 *
 *  @param image           The image.
 *  @param completionBlock The completion block.
 */
- (void)rotateToRightImage:(UIImage *)image completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

/**
 *  Rotates the given image 90 degrees to the left
 *
 *  @param image           The image.
 *  @param completionBlock The completion block.
 */
- (void)rotateToLeftImage:(UIImage *)image completionBlock:(ICPImageEngineImageProcessedBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
