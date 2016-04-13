//
//  ICPImageEditingAction.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPImageEditActionType.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Block executed on toolbar button touch up
 *
 *  @param image The current image
 *
 *  @return The edited image
 */
typedef UIImage *_Nonnull (^ICPImageEditingBlock)(UIImage *image);

/**
 *  An ICPImageEditingAction defines an action displayed or not in the ICPImageEditingController which intends to modify the
 * image displayed.
 */
@interface ICPImageEditingAction : NSObject

/**
 *  The action block
 */
@property (nonatomic, strong, readonly, nullable) ICPImageEditingBlock actionBlock;

/**
 *  The button image
 */
@property (nonatomic, strong, readonly) UIImage *image;

/**
 *  The action type
 */
@property (nonatomic, assign, readonly) ICPImageEditActionType actionType;

/**
 *  Create a custom ICPImageEditingAction
 *
 *  @param image       The bar button image
 *  @param actionBlock The action block to edit the image
 *
 *  @return the ICPImageEditingAction instance
 */
+ (instancetype)imageEditingActionWithImage:(UIImage *)image actionBlock:(ICPImageEditingBlock)actionBlock;

/**
 *  Create a default action provided by the SDK
 *
 *  @param actionType The action type
 *
 *  @return The image editing action
 */
+ (instancetype)imageEditingActionWithActionType:(ICPImageEditActionType)actionType;

/**
 *  Create a default action provided by the SDK and customise the image displayed for the button
 *
 *  @param image      The image for the button
 *  @param actionType The action type
 *
 *  @return The image editing action
 */
+ (instancetype)imageEditingActionWithImage:(UIImage *)image actionType:(ICPImageEditActionType)actionType;

@end

NS_ASSUME_NONNULL_END
