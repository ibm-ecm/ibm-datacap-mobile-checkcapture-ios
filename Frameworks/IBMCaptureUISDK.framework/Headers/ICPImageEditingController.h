//
//  ICPImageEditingController.h
//  IBMDatacapMobile
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPImageEngine;
@class ICPImageEditingController, ICPImageEditingAction;

/**
 *  Completion block called if user presses Done to save changes. If Cancel is called, completionBlock is not
 *executed.
 *
 *  @param controller       The ICPImageEditingController
 *  @param modifiedImage    The modified image
 *  @param imageWasModified A flag to indicate if any change was made to the image
 */
typedef void (^ICPImageEditingControllerCompletionBlock)(ICPImageEditingController *controller, UIImage *modifiedImage, BOOL imageWasModified);

/**
 The ICPImageEditingController is a controller used to rotate, deskew and editing brightness/contrast of the images stored in
 an ICPPage.
 */
@interface ICPImageEditingController : UIViewController

/**
 *  The tint color to apply to the controller
 */
@property (nonatomic, strong) UIColor *tintColor;

/**
 *  Method used to instantiate an ICPImageEditingController
 *
 *  @param originalImage   The original image. The modified Image is loaded but if document edges need to be changed the
 *original photo will be displayed.
 *  @param modifiedImage   The image to be edited
 *  @param imageEngine     An ICPImageEngine to perform the image editiion logic
 *  @param completionBlock The completion block called on Save/Done
 *
 *  @return ICPImageEditingController instance
 */
- (instancetype)initWithOriginaImage:(UIImage *)originalImage
                       modifiedImage:(UIImage *)modifiedImage
                         imageEngine:(id<ICPImageEngine>)imageEngine
                     completionBlock:(ICPImageEditingControllerCompletionBlock)completionBlock;


/**
 *  Add a toolbar button with corresponding action
 *
 *  @param imageEditingAction The ICPImageEditingAction
 */
- (void)addImageEditingAction:(ICPImageEditingAction *)imageEditingAction;

/**
 *  Define an action to be ran on presentation without user interaction.
 *
 *  @param imageEditingAction The ICPImageEditingAction
 */
- (void)runImageEditingActionOnPresentation:(ICPImageEditingAction *)imageEditingAction;


@end


NS_ASSUME_NONNULL_END
