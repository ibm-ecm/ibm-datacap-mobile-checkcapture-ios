//
//  ICPStatus.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPStatus_h
#define ICPStatus_h

#import <Foundation/Foundation.h>

/**
 The ICPStatus constant is an enumeration representing the upload status.
 */
typedef NS_ENUM(NSInteger, ICPStatus) {
    /** Status : Failed. */
    ICPStatusFailed = -1,
    /** Status : Incompleted. */
    ICPStatusIncompleted = 0,
    /** Status : Queued. */
    ICPStatusQueued = 1,
    /** Status : Uploading. */
    ICPStatusUploading = 2,
    /** Status : Uploaded. */
    ICPStatusUploaded = 3,
    /** Status : Saved */
    ICPStatusSaved = 4,
    /** Status : Temp file, for transactions */
    ICPStatusTemp = 5,
    /** Counter property for enum. */
    ICPStatusCount
};

#endif /* ICPStatus_h */
