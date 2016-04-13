//
//  ICPCameraController.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ICPCameraController;

@protocol ICPObjectFactory
, ICPBatchType, ICPBatch, ICPPage, ICPOcrEngine, ICPCameraControllerDelegate, ICPDocument;

/**
 *  This block is used to return an image to the camera controller
 *
 *  @param image image to be added to the camera roll view in the camera controller
 */
typedef void (^ICPCameraControllerImagePickedBlocked)(UIImage *_Nullable image);

/**
 *  This completion block is called when the next button is pressed in the camera controller
 *
 *  @param controller the camera controller
 *  @param batch      the ICPBatch currently being edited
 */
typedef void (^ICPCameraControllerCompletionBlock)(ICPCameraController *_Nullable controller,
                                                   id<ICPBatch> _Nullable batch,
                                                   id<ICPBatchType> _Nullable batchType);

/**
 The ICPCameraController is a complete UI widget for capturing and processing images and documents. You can present the
 controller
 as you would any standard UIViewController. It supports both iPhone and iPad layouts.

 You can customise the controller by adding buttons to the top toolbar, or changing the tint color.
 */
@interface ICPCameraController : UIViewController

/** The tint color to apply to the controller. The default value is ```[UINavigationBar appearance].tintColor```.*/
@property (nonatomic, strong, nullable) UIColor *tintColor;

/**
 When this is turned on and the batch type has information about barcodes to identify pages, the controller will scan the
 image for the page and
 document types through barcode identification. If the page type is detected, it will attempt to perform OCR on the fields if
 present in the DCO. This property is set to YES by default. Setting the property to NO will make the image processing faster.
 */
@property (nonatomic, assign) BOOL detectPageTypeThroughBarcode;

/**
 The object that acts as the delegate of camera controller.
 */
@property (nonatomic, weak) id<ICPCameraControllerDelegate> delegate;

/**
 *  Create a new instance of the controller using an object factory and batch type. The controller displays the documents
 *types available in the batch type in the top toolbar.
 *
 *  @param objectFactory   The object factory the controller will use to create and manage objects.
 *  @param batch           The batch to be loaded, if nil a new batch will be created
 *  @param currentDocument The current document to which pages will be added. The current document must be contained in the batch documents. If left nil, the last document in the batch is selected.
 *  @param batchType       The batch type to be used
 *  @param ocrEngine       the OCR Engine to be used to recognize characters in document
 *  @param completionBlock The completionBlock executed when pressing next in the controller
 *
 *  @return instance of ICPCameraController
 */
+ (nullable instancetype)controllerWithObjectFactory:(id<ICPObjectFactory>)objectFactory
                                               batch:(id<ICPBatch>)batch
                                     currentDocument:(nullable id<ICPDocument>)currentDocument
                                           batchType:(id<ICPBatchType>)batchType
                                           ocrEngine:(nullable id<ICPOcrEngine>)ocrEngine
                                     completionBlock:(nullable ICPCameraControllerCompletionBlock)completionBlock;

/**
 *  Add a custom button to the top toolbar of the camera controller.
 *
 *  @param title  The title of the button, displayed on iPad
 *  @param image  The icon of the button. Pass a UIImage with rendering mode UIImageRenderingModeAlwaysTemplate for the
 *tintColor to be reflected.
 *  @param target The target object
 *  @param action The action to perform on the target object once the button is pressed.
 *
 *  @return the ICPToolbarItem being added to the top toolbar
 */
- (nullable UIView *)addCustomButtonWithTitle:(nullable NSString *)title
                                        image:(nullable UIImage *)image
                                       target:(nullable id)target
                                       action:(nullable SEL)action;

/**
 *  Reset the camera controller with a previously saved batch
 *
 *  @param batch     the batch to load, if nil a new batch will be created
 *  @param batchType the batch type
 */
- (void)reloadWithBatch:(id<ICPBatch>)batch andBatchType:(id<ICPBatchType>)batchType;

@end

NS_ASSUME_NONNULL_END
