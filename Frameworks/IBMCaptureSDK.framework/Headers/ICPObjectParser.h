//
//  ICPBatchParser.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

@protocol ICPObject;

NS_ASSUME_NONNULL_BEGIN

/**
 Completion block used in the ICPObject parse
 
 @see ICPObjectParser
 
 @param success Flag to indicate if an error happened during the operation
 @param data    The data that represents an ICPObject
 @param error   If the parse fails, the reason will be provided as an error
 */
typedef void(^ICPObjectParserObjectCompletion)(BOOL success, NSData * _Nullable data, NSError * _Nullable error);


/**
 The ICPObjectParser is responsable for converting the ICPObjects into a NSData that can be send to an external server or saved locally.
 The objects that can be converted are:
 
 @see ICPObject
 @see ICPField
 @see ICPCharacter
 @see ICPPage
 @see ICPDocument
 @see ICPBatch
 */
@protocol ICPObjectParser <NSObject>


/**
 This method is responsable to parse a given ICPObject.
 
 @param object      The ICPObject that will be parsed
 @param completion  Block that is called once that the parse is completed
 */
- (void)parseObject:(id<ICPObject>)object withCompletion:(ICPObjectParserObjectCompletion)completion;

@end

NS_ASSUME_NONNULL_END
