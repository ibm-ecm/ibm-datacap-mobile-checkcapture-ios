//
//  ICPFilterType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

/**
 The ICPFilterType constant is used to specify the filter types that may be applied via image processing.

 @see ICPImageEngine
 */
typedef NS_ENUM(NSUInteger, ICPFilterType) {
    /** Applies Black and White filter. */
    ICPFilterTypeBlackAndWhite = 0,
    /** Applies Grayscale filter. */
    ICPFilterTypeGrayscale,
    /** Counter property for enum. */
    ICPFilterTypeCount
};

NS_ASSUME_NONNULL_END
