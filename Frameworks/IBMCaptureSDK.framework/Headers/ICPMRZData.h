//
//  ICPMRZData.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ICPMRZField;

@interface ICPMRZData : NSObject

@property (nonatomic, strong, readonly) ICPMRZField *type;
@property (nonatomic, strong, readonly) ICPMRZField *subType;
@property (nonatomic, strong, readonly) ICPMRZField *countryCode;
@property (nonatomic, strong, readonly) ICPMRZField *nationality;
@property (nonatomic, strong, readonly) ICPMRZField *surname;
@property (nonatomic, strong, readonly) ICPMRZField *givenName;
@property (nonatomic, strong, readonly) ICPMRZField *sex;
@property (nonatomic, strong, readonly) ICPMRZField *birthdate;
@property (nonatomic, strong, readonly) ICPMRZField *passportExpirationDate;
@property (nonatomic, strong, readonly) ICPMRZField *passportNumber;
@property (nonatomic, strong, readonly) ICPMRZField *personalId;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithType:(ICPMRZField *)type
                     subType:(ICPMRZField *)subType
                 countryCode:(ICPMRZField *)countryCode
                 nationality:(ICPMRZField *)nationality
                     surname:(ICPMRZField *)surname
                   givenName:(ICPMRZField *)givenName
                         sex:(ICPMRZField *)sex
                   birthdate:(ICPMRZField *)birthdate
      passportExpirationDate:(ICPMRZField *)passportExpirationDate
              passportNumber:(ICPMRZField *)passportNumber
                  personalId:(ICPMRZField *)personalId NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
