//
//  ICPError.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPError_h
#define ICPError_h

typedef NS_ENUM(NSInteger, ICPError) {
    ICPErrorAuthentication = -1000,
    ICPErrorBatchNotQueued = -1001,
    ICPErrorBadFormatedParameters = -1002,
    ICPErrorUserCancelledAuthentication = -1003
};

#endif /* ICPError_h */
