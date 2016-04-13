//
//  ICPDatacapStorageManager.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPStorageProvider.h"

NS_ASSUME_NONNULL_BEGIN

@class IBMDatacap;
@class ICPStorageHelper;
@class ICPDatacapResponseHandler;
@class ICPDatacapRequestHandler;

@protocol ICPDatacapService;
@protocol ICPLoginProvider;
@protocol ICPObjectFactory;


/**
 The ICPDatacapStorageProvider is an implementation of ICPStorageProvider responsable to storage the files in the Datacap server.
 */
@interface ICPDatacapStorageProvider : NSObject <ICPStorageProvider>

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPDatacapStorageProvider is an implementation of ICPStorageProvider responsable to storage the files in the Datacap server.
 
 @param datacap         IBMDatacap that will handle the requests to the datacap server
 @param service         ICPDatacapService with the server configuration
 @param responseHandler ICPDatacapResponseHandler that will handle the response from the server
 @param requestHandler  ICPDatacapRequestHandler that will handle the request to the server
 @param storageHelper   ICPStorageHelper used to load files from the disk
 @param objectFactory   Application's ICPObjectFactory
 @param loginProvider   ICPLoginProvider used to authenticate in the datacap server
 
 @see ICPDatacapResponseHandler
 @see ICPDatacapRequestHandler
 
 @return An ICPDatacapStorageProvider instance
 */
- (instancetype)initWithDatacap:(IBMDatacap *)datacap
                        service:(id<ICPDatacapService>)service
                responseHandler:(ICPDatacapResponseHandler *)responseHandler
                 requestHandler:(ICPDatacapRequestHandler *)requestHandler
                  storageHelper:(ICPStorageHelper *)storageHelper
                  objectFactory:(id<ICPObjectFactory>)objectFactory
               andLoginProvider:(id<ICPLoginProvider>)loginProvider NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
