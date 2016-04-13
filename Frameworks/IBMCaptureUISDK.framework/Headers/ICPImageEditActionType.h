//
//  ICPImageEditActionType.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

/**
 *  Type for image editing action that can be used in ICPImageEditingController. Some actions are provided by the SDK.
 */
typedef NS_OPTIONS(NSUInteger, ICPImageEditActionType) {
    /**
     *  Action to rotate image clockwise by 90 degrees
     */
    ICPImageEditActionTypeRotateRight = 0,
    /**
     *  Action to rotate image anti-clockwise by 90 degrees
     */
    ICPImageEditActionTypeRotateLeft,
    /**
     *  Action to manually deskew document inside image
     */
    ICPImageEditActionTypeDeskew,
    /**
     *  Action to popup contrast and brightness filters
     */
    ICPImageEditActionTypeFilters,
    /**
     *  Action to auto deskew. Attempt to find 4 corners of document and crops image.
     */
    ICPImageEditActionTypeAutoDeskew,
    /**
     *  Action defined by the developer using the SDK
     */
    ICPImageEditActionTypeCustom
};
