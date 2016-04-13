//
//  ICPCameraViewValidationRule.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

/**
 *  This is used to return the validation result of the present camera view frame. For a document to be recognized as
 * detected, all conditions must be met and therefore set to 1.
 */
typedef NS_OPTIONS(NSUInteger, ICPCameraViewState) {
    
    ICPCameraViewStateLookingForDocument = 0,
    
    ICPCameraViewStateInvalidRatio,
    
    ICPCameraViewStateDocumentTooSmall,
    
    ICPCameraViewStateCameraMoving,
    
    ICPCameraViewStateDocumentDetected,
    
    ICPCameraViewStateCannotDetectTextInDocument
    
};
