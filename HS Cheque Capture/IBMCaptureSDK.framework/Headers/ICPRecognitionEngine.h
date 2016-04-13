//
//  ICPRecognitionEngine.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#ifndef ICPRecognitionEngine_h
#define ICPRecognitionEngine_h

/**
 *  Supported recognition engines on server side @see -recognizePageFields:keepAlive:recognitionEngine:completionBlock:
 */
typedef NS_ENUM(NSUInteger, ICPRecognitionEngine) {
    /**
     *  OCR/A
     */
    ICPRecognitionEngineABBYY = 0,
    /**
     *  ICR/C
     */
    ICPRecognitionEngineNUANCE,
    /**
     *  OCR/SR
     */
    ICPRecognitionEngineOPENTEXT,
    /**
     *  Default: OCR/A
     */
    ICPRecognitionEngineDefault
};

#endif /* ICPRecognitionEngine_h */
