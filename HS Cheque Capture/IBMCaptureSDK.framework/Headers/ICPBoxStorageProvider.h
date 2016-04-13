//
//  ICPBoxStorageProvider.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPStorageProvider.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ICPLoginProvider, ICPObjectFactory, ICPObjectParser;
@class ICPBoxSDKHelper, ICPStorageHelper;

/**
 The ICPBoxStorageProvider is an implementation of ICPStorageProvider responsable to storage the files in the Box cloud service.
 To do so, the ICPBatch is converted to a file with it informations, and the ICPPage objects are converted to two files each.
 One for the page informations and other with the page image saved as a compressed JPG.
 
 These files will be uploaded to the folder with the same name of the batch type, inside the /DatacapApplications, ending with
 the path structure:
 
 <i>/DatacapApplications/Application/<batch id>/<batch id>.xml</i>
 
 <i>/DatacapApplications/Application/<batch id>/<page id>.xml</i>
 
 <i>/DatacapApplications/Application/<batch id>/<page id>.jpg</i>
 
 
 @see ICPStorageProvider
 @see ICPBatch
 @see ICPPage
 */
@interface ICPBoxStorageProvider : NSObject <ICPStorageProvider>

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPBoxStorageProvider is an implementation of ICPStorageProvider responsable to storage the files in the Box cloud service.
 
 @param loginProvider   ICPLoginProvider responsable to handle the Box login
 @param objectFactory   Application's ICPObjectFactory
 @param batchParser     ICPObjectParser that will be used to parse the ICPBatch informations into a file
 @param pageParser      ICPObjectParser that will be used to parse the ICPPage informations into a file
 @param storageHelper   ICPStorageHelper used to load the page images from the disk
 @param helper          ICPBoxSDKHelper used to perform the Box SDK operations
 
 @return A configurated ICPBoxStorageProvider instance
 */
- (instancetype) initWithLoginProvider:(id<ICPLoginProvider>)loginProvider
                         objectFactory:(id<ICPObjectFactory>)objectFactory
                           batchParser:(id<ICPObjectParser>)batchParser
                            pageParser:(id<ICPObjectParser>)pageParser
                         storageHelper:(ICPStorageHelper *)storageHelper
                          andBoxHelper:(ICPBoxSDKHelper *)helper NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
