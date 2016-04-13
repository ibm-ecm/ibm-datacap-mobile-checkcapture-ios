//
//  ICPTesseractOcrEngine.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ICPOcrEngine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An OCR engine that conforms to the ICPOcrEngine protocol
 */
@interface ICPTesseractOcrEngine : NSObject <ICPOcrEngine>

@property (nonatomic, strong, readonly) NSString *tessDataAbsolutePath;

/**
 Initialise the Tesseract engine with traineddata files to use and their location

 @param tessDataPrefixes array of prefix strings for the .traineddata files. To use eng.traineddata and rus.traineddata, pass
 @"eng" and @"rus" in the NSArray. If none is supplied will default to @"eng".
 @param absolute path to the parent folder of the tessdata folder containing the traineddata files. If none is supplied, the
 engine will look in the root directory of the main bundle.
 */

/**
 *  Initialise the Tesseract engine with traineddata files to use and their location
 *
 *  @param tessDataPrefixes array of prefix strings for the .traineddata files. To use eng.traineddata and rus.traineddata,
 pass
 @"eng" and @"rus" in the NSArray. If none is supplied will default to @"eng".
 *  @param path             absolute path to the parent folder of the tessdata folder containing the traineddata files. If
 none is supplied, the
 engine will look in the root directory of the main bundle.
 *
 *  @return instance of ICPTesseractOcrEngine
 */
- (id)initWithTessDataPrefixes:(NSArray *)tessDataPrefixes andTessdataAbsolutePath:(NSString *)path;

/**
 *  Reconfigure the Tesseract engine at runtime with traineddata files to use and their location
 *
 *  @param tessDataPrefixes array of prefix strings for the .traineddata files. To use eng.traineddata and rus.traineddata,
 pass
 @"eng" and @"rus" in the NSArray. If none is supplied will default to @"eng".
 *  @param path             absolute path to the parent folder of the tessdata folder containing the traineddata files. If
 none is supplied, the
 engine will look in the root directory of the main bundle.
 *
 *  @return instance of ICPTesseractOcrEngine
 */
- (void)reconfigureWithTessDataPrefixes:(NSArray *)tessDataPrefixes andTessdataAbsolutePath:(NSString *)dataPath;

@end

NS_ASSUME_NONNULL_END
