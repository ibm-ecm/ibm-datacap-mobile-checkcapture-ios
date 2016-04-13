//
//  ICPPage.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ICPObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The ICPPage protocol contains an original image, a modified image, and a thumbnail.

 The ICPPage protocol contains fields that it inherits from the ICPObject protocol.

 @see ICPObject
 */
@protocol ICPPage <ICPObject>

/** The original image of the page, prior to any processing. */
@property (nonatomic, strong, nullable) UIImage *originalImage;

/** The modified image, normally after the last set of image processing has been performed. */
@property (nonatomic, strong, nullable) UIImage *modifiedImage;

/** A thumbnail of the modified image, useful for displaying in the user interface. It is updated automatically when the
 * modifiedImage is updated. */
@property (nonatomic, strong, readonly, nullable) UIImage *thumbnailImage;

@end

NS_ASSUME_NONNULL_END
