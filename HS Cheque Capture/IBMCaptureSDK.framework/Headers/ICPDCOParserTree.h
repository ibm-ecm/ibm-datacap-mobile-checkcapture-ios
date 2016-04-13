//
//  DCOParserTree.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol ICPBatchType;

/**
 This class represents the xml configuration file structure.
 */
@protocol ICPDCOParserTree <NSObject>

/** This configuration is the ICPBatchType processed by the instance of the tree */
@property (nonatomic, strong, readonly) id<ICPBatchType> configuration;

/**
 @param nodeType    The type of the node, usually represented by the element name
 @param attributes  The attributes listed in the element tag
 */
- (void) addNodeOfType:(NSString *)nodeType withAttributes:(NSDictionary *)attributes;

/**
 Update the current node by providing the text found the element content
 
 @param nodeContent The text found on the element content
 */
- (void) updateCurrentNodeWithString:(NSString *)nodeContent;

/**
 Closes the current node and navigate up on the data tree
 
 @param nodeType    The type of the node, usually represented by the element name
 */
- (void) releaseLeafOfType:(NSString *)nodeType;

@end

NS_ASSUME_NONNULL_END
