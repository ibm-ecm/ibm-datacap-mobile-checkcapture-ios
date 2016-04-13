//
//  ICPCheckCountry.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPCheckCountry_h
#define ICPCheckCountry_h

/**
 *  Supported countries @see -processCheck:checkCountry:completionBlock:
 */
typedef NS_ENUM(NSUInteger, ICPCheckCountry) {
    /**
     *  Brazil
     */
    ICPCheckCountryBrazil = 0,
    /**
     *  Canada
     */
    ICPCheckCountryCanada = 1,
    /**
     *  France
     */
    ICPCheckCountryFrance = 2,
    /**
     *  United-Kingdom
     */
    ICPCheckCountryUK = 3,
    /**
     *  United States of America
     */
    ICPCheckCountryUSA = 4,
    /**
     *  Default: USA
     */
    ICPCheckCountryDefault
};

#endif /* ICPCheckCountry_h */
