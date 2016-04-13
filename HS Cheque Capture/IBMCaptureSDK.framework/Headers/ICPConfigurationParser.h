//
//  ICPConfigurationParser.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ICPBatchType;

NS_ASSUME_NONNULL_BEGIN

/**
 Completion block used in the configuration file parse
 
 @see ICPConfigurationParser
 
 @param success         Flag to indicate if an error happened during the operation
 @param configuration   The type retrieved from the configuration file
 @param error           If the parse fails, the reason will be provided as an error
*/
typedef void(^ICPConfigurationParserCompletion)(BOOL success, id<ICPBatchType> _Nullable configuration, NSError * _Nullable error);

/**
 The ICPConfigurationParser is responsable to parse the configuration file (dco) into type objects
 
 @see ICPBatchType
*/
@protocol ICPConfigurationParser <NSObject>

/**
 This method is responsable to convert a configuration file into a ICPBatchType
 
 @see ICPBatchType
 
 @param data        The NSData that represents the document download from the server with the configuration information
 @param completion  Block that is called once the parse is complete
 */
- (void) parseData:(NSData *)data withCompletion:(ICPConfigurationParserCompletion)completion;

@end

NS_ASSUME_NONNULL_END
