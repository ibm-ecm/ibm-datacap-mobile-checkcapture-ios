//
//  ICPTransactionManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPRecognitionEngine.h"
#import "ICPCheckCountry.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPPage;
@protocol ICPPageType;
@protocol ICPField;

typedef void(^ICPFieldsRemoteComputationCompletionBlock)(BOOL success, NSArray<id<ICPField>> *fields, NSError * error);
typedef void(^ICPPageRemoteComputationCompletionBlock)(BOOL success, id<ICPPage> _Nullable page, NSError * error);

@protocol ICPRemoteComputationProvider <NSObject>

/**
 *  Recognize Page Fields
 *
 *  @param page                 The page with fields pre-populated with Position
 *  @param locale               Locale to be used by recognition. Default is (en-US)
 *  @param timeout              Timeout for transaction execution on server side.
 *  @param recognitionEngine    The engine to use for OCR recogntion on server side
 *  @param completionBlock      The completion block
 */
- (void)recognizePageFields:(id<ICPPage>)page
                     locale:(NSLocale * _Nullable)locale
                    timeout:(NSUInteger)timeout
          recognitionEngine:(ICPRecognitionEngine)recognitionEngine
            completionBlock:(ICPFieldsRemoteComputationCompletionBlock)completionBlock;

/**
 *  Process Check by default. If the DCO at page level has the following variables (i.e. TransactionApplication,
 * TransactionRulesets, TransactionWorkflow), these will be used for the executeTransaction parameters.
 *
 *  @param checkFrontPage  ICPPage for the front of the check
 *  @param checkCountry    The country for the check
 *  @param locale            Locale to be used by recognition. Default is (en-US)
 *  @param timeout         Timeout for transaction execution on server side.
 *  @param completionBlock The completion block
 */
- (void)processCheck:(id<ICPPage>)checkFrontPage
        checkCountry:(ICPCheckCountry)checkCountry
              locale:(NSLocale * _Nullable)locale
             timeout:(NSUInteger)timeout
     completionBlock:(ICPPageRemoteComputationCompletionBlock)completionBlock;

/**
 *  Recognize text in fields
 *
 *  @param fields            The fields with position to OCR
 *  @param locale            Locale to be used by recognition. Default is (en-US)
 *  @param timeout           Timeout for transaction execution on server side.
 *  @param recognitionEngine The OCR recognition engine to use
 *  @param completionBlock   The completion block
 */
- (void)recognizeFields:(NSArray<id<ICPField> > *)fields
                 locale:(NSLocale * _Nullable)locale
                timeout:(NSUInteger)timeout
      recognitionEngine:(ICPRecognitionEngine)recognitionEngine
        completionBlock:(ICPFieldsRemoteComputationCompletionBlock)completionBlock;

/**
 *  Recognize text in fields
 *
 *  @param field             The field with position to OCR
 *  @param locale            Locale to be used by recognition. Default is (en-US)
 *  @param timeout           Timeout for transaction execution on server side.
 *  @param recognitionEngine The OCR recognition engine to use
 *  @param completionBlock   The completion block
 */
- (void)recognizeField:(id<ICPField>)field
                locale:(NSLocale * _Nullable)locale
               timeout:(NSUInteger)timeout
     recognitionEngine:(ICPRecognitionEngine)recognitionEngine
       completionBlock:(ICPFieldsRemoteComputationCompletionBlock)completionBlock;

/**
 *  Updates page fields with server-side results
 *
 *  @param page            The page to be updated
 *  @param result          The result of a previous transaction
 *  @param skip            if YES, will not modify fields with prior text
 *  @param completionBlock The completion block
 */
- (void)updatePage:(id<ICPPage>)page
       withResults:(NSArray<id<ICPField>> *)result
skipNonBlankFields:(BOOL)skip
andCompletionBlock:(ICPPageRemoteComputationCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
