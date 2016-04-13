//
//  ICPDCOObjectType.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPDCOObjectType_h
#define ICPDCOObjectType_h

#import <Foundation/Foundation.h>

/** 
 Enum used by the ICPConfigurationParser and ICPObjectParser to translate the element names to objects
 */
typedef NS_ENUM(NSUInteger, ICPDCOObjectType) {
    ICPDCOObjectTypeUnkwown = 0,
    ICPDCOObjectTypeSetup,
    ICPDCOObjectTypeBatch,
    ICPDCOObjectTypeDocument,
    ICPDCOObjectTypePage,
    ICPDCOObjectTypeField,
    ICPDCOObjectTypeProperty,
    ICPDCOObjectTypeCharacter,
    ICPDCOObjectTypeDict,
    ICPDCOObjectTypeDictMember,
    ICPDCOObjectTypeCount
};

#endif
