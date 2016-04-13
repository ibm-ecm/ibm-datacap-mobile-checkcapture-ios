//
//  ICPTransactionFile.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN


/**
 *  @brief  An object describing a temporary transaction file on the server. The file can be downloaded using the fileName.
 * @see - (void)getTransactionFile:withCompletionBlock:
 */
@protocol ICPTransactionFile

/**
 *  Created date
 */
@property (nonatomic, strong, readonly) NSDate *createdDate;

/**
 *  File name
 */
@property (nonatomic, strong, readonly) NSString *fileName;

/**
 *  Modified date
 */
@property (nonatomic, strong, readonly) NSDate *modifiedDate;

/**
 *  Returns YES if file has been modified
 */
@property (nonatomic, assign, readonly) BOOL isModified;

/**
 *  Returns YES if file is new
 */
@property (nonatomic, assign, readonly) BOOL isNew;

@end

NS_ASSUME_NONNULL_END
