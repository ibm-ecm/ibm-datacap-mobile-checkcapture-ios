//
//  ICPTransactionFileListMode.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPTransactionFileListMode_h
#define ICPTransactionFileListMode_h

/**
 *  Transactional List modes @see -getTransactionFileList:withCompletionBlock:
 */
typedef NS_ENUM(NSUInteger, ICPTransactionFileListMode) {
    /**
     *  Return all files
     */
    ICPTransactionFileListModeAll = 0,
    /**
     *  Return new files only
     */
    ICPTransactionFileListModeNew,
    /**
     *  Return modified files only
     */
    ICPTransactionFileListModeModified
};

#endif /* ICPTransactionFileListMode_h */
