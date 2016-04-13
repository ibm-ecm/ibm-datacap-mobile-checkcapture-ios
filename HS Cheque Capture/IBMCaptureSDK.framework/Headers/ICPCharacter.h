//
//  ICPCharacter.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPObject.h"

#import "ICPRect.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The ICPCharacter describe a character recognized in the ICPField value
 */
@protocol ICPCharacter <ICPObject>

/**
 *  Frame of the character recognised by OCR
 */
@property (nonatomic, assign, readonly) ICPRect frame;

/**
 *  Confidence between 0 and 1 as set by OCR
 */
@property (nonatomic, assign) double confidence;

/**
 *  Character string. This contains a string of length 1 with the unicode character
 */
@property (nonatomic, strong, readonly) NSString *text;

@end

NS_ASSUME_NONNULL_END
