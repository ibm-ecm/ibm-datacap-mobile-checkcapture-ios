//
//  IBMCapture.h
//  IBMCaptureSDK
//
//  Copyright (c) 2016 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for IBMCapture.
FOUNDATION_EXPORT double IBMCaptureVersionNumber;

//! Project version string for IBMCapture.
FOUNDATION_EXPORT const unsigned char IBMCaptureVersionString[];

#pragma mark - Base objects

#import <IBMCaptureSDK/ICPCapture.h>
#import <IBMCaptureSDK/ICPCapture+Service.h>
#import <IBMCaptureSDK/ICPTransactionFile.h>

#import <IBMCaptureSDK/ICPSessionManager.h>
#import <IBMCaptureSDK/ICPRemoteComputationManager.h>
#import <IBMCaptureSDK/ICPConfigurationProvider.h>
#import <IBMCaptureSDK/ICPLoginProvider.h>
#import <IBMCaptureSDK/ICPRemoteComputationProvider.h>
#import <IBMCaptureSDK/ICPStorageProvider.h>
#import <IBMCaptureSDK/ICPConfigurationParser.h>
#import <IBMCaptureSDK/ICPObjectParser.h>
#import <IBMCaptureSDK/ICPDCOParser.h>
#import <IBMCaptureSDK/ICPSetupDCOParserTree.h>
#import <IBMCaptureSDK/ICPDCOParserTree.h>
#import <IBMCaptureSDK/ICPDCOObjectType.h>
#import <IBMCaptureSDK/ICPDCOObjectParser.h>
#import <IBMCaptureSDK/ICPIDProcessor.h>
#import <IBMCaptureSDK/ICPMRZDecoder.h>
#import <IBMCaptureSDK/ICPMRZData.h>
#import <IBMCaptureSDK/ICPMRZField.h>
#import <IBMCaptureSDK/ICPMRZField+NSDate.h>
#import <IBMCaptureSDK/ICPError.h>

#pragma mark - Datacap Managers

#import <IBMCaptureSDK/ICPDatacapHelper.h>
#import <IBMCaptureSDK/ICPSessionManager+Datacap.h>
#import <IBMCaptureSDK/ICPRemoteComputationManager+Datacap.h>
#import <IBMCaptureSDK/ICPDatacapConfigurationProvider.h>
#import <IBMCaptureSDK/ICPDatacapLoginProvider.h>
#import <IBMCaptureSDK/ICPDatacapRemoteComputationProvider.h>
#import <IBMCaptureSDK/ICPDatacapStorageProvider.h>
#import <IBMCaptureSDK/ICPCapture+Datacap.h>

#pragma mark - Box Managers

#import <IBMCaptureSDK/ICPBoxLoginProvider.h>
#import <IBMCaptureSDK/ICPSessionManager+Box.h>
#import <IBMCaptureSDK/ICPBoxConfigurationProvider.h>
#import <IBMCaptureSDK/ICPBoxHelper.h>
#import <IBMCaptureSDK/ICPBoxSDKHelper.h>
#import <IBMCaptureSDK/ICPBoxItem.h>
#import <IBMCaptureSDK/ICPBoxStorageProvider.h>
#import <IBMCaptureSDK/ICPCapture+BOX.h>

#pragma mark - Enum and types

#import <IBMCaptureSDK/ICPCaptureCompletionBlock.h>
#import <IBMCaptureSDK/ICPStatus.h>
#import <IBMCaptureSDK/ICPIndex.h>
#import <IBMCaptureSDK/ICPCheckCountry.h>
#import <IBMCaptureSDK/ICPRecognitionEngine.h>
#import <IBMCaptureSDK/ICPTransactionFileListMode.h>

#pragma mark - Model

#import <IBMCaptureSDK/ICPBatch.h>
#import <IBMCaptureSDK/ICPBatchType.h>
#import <IBMCaptureSDK/ICPCharacter.h>
#import <IBMCaptureSDK/ICPDatacapService.h>
#import <IBMCaptureSDK/ICPDocument.h>
#import <IBMCaptureSDK/ICPDocumentType.h>
#import <IBMCaptureSDK/ICPField.h>
#import <IBMCaptureSDK/ICPFieldType.h>
#import <IBMCaptureSDK/ICPObject.h>
#import <IBMCaptureSDK/ICPObjectFactory.h>
#import <IBMCaptureSDK/ICPObjectType.h>
#import <IBMCaptureSDK/ICPPage.h>
#import <IBMCaptureSDK/ICPPageType.h>
#import <IBMCaptureSDK/ICPPersistentObjectFactory.h>
#import <IBMCaptureSDK/ICPRect.h>
#import <IBMCaptureSDK/ICPService.h>
#import <IBMCaptureSDK/ICPApplication.h>
#import <IBMCaptureSDK/ICPJob.h>
#import <IBMCaptureSDK/ICPStation.h>
#import <IBMCaptureSDK/ICPWorkflow.h>
#import <IBMCaptureSDK/ICPSetupDCO.h>

#pragma mark - Utils

#import <IBMCaptureSDK/ICPBarcode.h>
#import <IBMCaptureSDK/ICPBarcodeEngine.h>
#import <IBMCaptureSDK/ICPCoreImageImageEngine.h>
#import <IBMCaptureSDK/ICPFilterType.h>
#import <IBMCaptureSDK/ICPImageEngine.h>
#import <IBMCaptureSDK/ICPOcrEngine.h>
#import <IBMCaptureSDK/ICPTesseractOcrEngine.h>
#import <IBMCaptureSDK/ICPZXingBarcodeEngine.h>
