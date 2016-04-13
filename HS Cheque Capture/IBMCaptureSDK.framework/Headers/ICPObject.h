//
//  ICPObject.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import "ICPStatus.h"


NS_ASSUME_NONNULL_BEGIN

@protocol ICPObjectType
, ICPField, ICPFieldType;

/**
 The ICPObject protocol is the root object class for all IBM Capture domain classes.
 */
@protocol ICPObject <NSObject>

/**
 *  The type of this object, usually defined by the remote service. Use the object factory to change the type @see
 * ICPObjectFactory -(void)setObjectType:forObject:
 */
@property (nonatomic, strong, readonly, nullable) id<ICPObjectType> type;

/** The upload status of this object */
@property (nonatomic, assign) ICPStatus status;

/** An NSArray of ICPField objects belonging to this ICPObject instance */
@property (nonatomic, strong) NSArray<id<ICPField> > *fields;

/** An NSDictionary with the values of the properties/variables */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *dcoDictionary;

/** The ICPObject the object belongs to */
@property (nonatomic, strong, nullable, readonly) id<ICPObject> parentObject;

- (id<ICPField>)createFieldWithType:(id<ICPFieldType>)fieldType;

/**
 Add a field to this object
 @param field The field to add
 */
- (void)addField:(id<ICPField>)field;

/**
 Remove a field from this object
 @param field The field to remove
 */
- (void)removeField:(id<ICPField>)field;

@end

NS_ASSUME_NONNULL_END
