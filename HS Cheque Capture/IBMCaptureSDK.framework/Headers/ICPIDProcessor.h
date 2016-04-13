//
//  ICPIDProcessor.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ICPOcrEngine;
@class ICPMRZData;

NS_ASSUME_NONNULL_BEGIN

/**
 Block used to report the data read from a passport image
 
 @param mrzString   The mrz string found in the image
 @param mrzData     The mrz information extracted from the string
 
 @see ICPMRZData
 */
typedef void(^ICPIDProcessorPassportCompletion)(NSString * _Nullable mrzString, ICPMRZData * _Nullable mrzData);

/**
 The ICPIDProcessor is responsable for, given an image and a type, extract the ID informations
 */
@interface ICPIDProcessor : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 The ICPIDProcessor is responsable for, given an image and a type, extract the ID informations
 
 @param ocrEngine Engine used to recognize texts
 
 @see ICPOcrEngine
 */
- (instancetype)initWithOCREngine:(id<ICPOcrEngine>)ocrEngine NS_DESIGNATED_INITIALIZER;

/**
 Method used to process an image of a passport and extract the MRZ information.
 
 @param passport    The image with the photo of a passport, where the mrz string must be visible
 @param completion  The block that will be called once the operation is completed
 
 @see ICPMRZDecoder
 */
- (void)processPassportImage:(UIImage *)passport
              withCompletion:(ICPIDProcessorPassportCompletion)completion;

@end

NS_ASSUME_NONNULL_END
