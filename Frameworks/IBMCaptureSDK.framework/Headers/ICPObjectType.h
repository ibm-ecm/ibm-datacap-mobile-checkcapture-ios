//
//  ICPObjectType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ICPFieldType;

/** ICPObjectType is a protocol that represents the object type. */
@protocol ICPObjectType <NSObject>

/** The type of the object. */
@property (nonatomic, strong, readonly) NSString *typeId;

/** An NSArray of available field types. */
@property (nonatomic, strong) NSArray<id<ICPFieldType> > *fieldTypes;

/** An NSDictionary with the values of the properties/variables */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *dcoDictionary;

@end

NS_ASSUME_NONNULL_END
