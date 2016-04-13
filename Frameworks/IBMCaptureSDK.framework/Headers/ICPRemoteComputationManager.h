//
//  ICPRemoteOperationsManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPCheckCountry.h"
#import "ICPRecognitionEngine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPLoginProvider;
@protocol ICPRemoteComputationProvider;
@protocol ICPPage;
@protocol ICPField;


typedef void(^ICPRemoteProcessFieldsCompletionBlock)(BOOL success, NSArray<id<ICPField>> *fields, NSError * _Nullable error);
typedef void(^ICPRemoteUpdatePageCompletionBlock)(BOOL success, id<ICPPage> page, NSError * _Nullable error);

/**
 The ICPRemoteComputationManager is responsable for configure and manage the calls for the ICPRemoteComputationProvider
 
 @see ICPRemoteComputationProvider
 */
@interface ICPRemoteComputationManager : NSObject

/** Mark if the transactions depends on a valid session  */
@property (nonatomic, assign) BOOL transactionSecurityEnabled;
/** Timeout for transaction execution on server side. Default is 60000ms */
@property (nonatomic, assign) NSUInteger executeTimeout;
/** NSLocale used to OCR on fields */
@property (nonatomic, assign) NSLocale *fieldsLocale;

- (instancetype)init NS_UNAVAILABLE;

/**
 The ICPRemoteComputationManager is responsable for configure and manage the calls for the ICPRemoteComputationProvider
 
 @param loginProvider               ICPLoginProvider used to authenticate the user in the server
 @param remoteOperationsProvider    ICPRemoteComputationProvider that will be used to comunicate with the server
 
 @see ICPLoginProvider
 @see ICPRemoteComputationProvider
 
 @return An ICPRemoteComputationManager instance
 */
- (instancetype)initWithLoginProvider:(id<ICPLoginProvider>)loginProvider
         andRemoteComputationProvider:(id<ICPRemoteComputationProvider>)remoteOperationsProvider NS_DESIGNATED_INITIALIZER;

/**
 *  Process Check by default. If the DCO at page level has the following variables (i.e. TransactionApplication,
 * TransactionRulesets, TransactionWorkflow), these will be used for the executeTransaction parameters.
 *
 *  @param checkFrontPage  ICPPage for the front of the check
 *  @param checkCountry    The country for the check
 *  @param completionBlock The completion block
 */
- (void)processCheck:(id<ICPPage>)checkFrontPage
        checkCountry:(ICPCheckCountry)checkCountry
     completionBlock:(ICPRemoteProcessFieldsCompletionBlock)completionBlock;

/**
 *  @brief  Updates page fields with server-side results
 *
 *  @param page            The page to be updated
 *  @param result          The result of a previous transaction
 *  @param skip            if YES, will not modify fields with prior text
 *  @param completionBlock The completion block
 */
- (void)updatePage:(id<ICPPage>)page
       withResults:(NSArray<id<ICPField>> *)result
skipNonBlankFields:(BOOL)skip
andCompletionBlock:(ICPRemoteUpdatePageCompletionBlock)completionBlock;

/**
 *  Recognize text in fields
 *
 *  @param fields            The fields with position to OCR
 *  @param recognitionEngine The OCR recognition engine to use
 *  @param completionBlock   The completion block
 */
- (void)recognizeFields:(NSArray<id<ICPField> > *)fields
      recognitionEngine:(ICPRecognitionEngine)recognitionEngine
        completionBlock:(ICPRemoteProcessFieldsCompletionBlock)completionBlock;

/**
 *  Recognize Page Fields
 *
 *  @param page                 The page with fields pre-populated with Position
 *  @param recognitionEngine    The engine to use for OCR recogntion on server side
 *  @param completionBlock      The completion block
 */
- (void)recognizePageFields:(id<ICPPage>)page
          recognitionEngine:(ICPRecognitionEngine)recognitionEngine
            completionBlock:(ICPRemoteProcessFieldsCompletionBlock)completionBlock;

/**
 *  Recognize text in fields
 *
 *  @param field             The field with position to OCR
 *  @param recognitionEngine The OCR recognition engine to use
 *  @param completionBlock   The completion block
 */
- (void)recognizeField:(id<ICPField>)field
     recognitionEngine:(ICPRecognitionEngine)recognitionEngine
       completionBlock:(ICPRemoteProcessFieldsCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
