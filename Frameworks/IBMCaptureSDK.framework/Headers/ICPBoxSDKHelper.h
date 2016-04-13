//
//  ICPBoxHelper.h
//  IBMCaptureSDK
//
//  Copyright © 2016 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ICPBoxItem;

NS_ASSUME_NONNULL_BEGIN

typedef void(^ICPBoxHelperFolderListBlock)(BOOL success, NSString *folderId, NSArray<ICPBoxItem *> *items, NSError * _Nullable error);
typedef void(^ICPBoxHelperDownloadFileBlock)(BOOL success, NSData * _Nullable content, NSError * _Nullable error);
typedef void(^ICPBoxHelperRootLookupBlock)(BOOL success, NSString * _Nullable folderName, NSString * _Nullable folderId, NSError * _Nullable error);
typedef void(^ICPBoxHelperOperationBlock)(BOOL success, NSError * _Nullable error);
typedef void(^ICPBoxHelperProgressBlock)(float progress);
typedef void(^ICPBoxHelperFileUpdateBlock)(BOOL success, NSString * _Nullable fileName, NSString * _Nullable fileId, NSError * _Nullable error);
typedef void(^ICPBoxHelperNavigationBlock)(BOOL success, NSString * _Nullable folderId, NSArray<ICPBoxItem *> *items, NSError *error);

/**
 The ICPBoxSDKHelper encapsulate the Box sdk operations 
 */
@interface ICPBoxSDKHelper : NSObject

/** 
 The name of the root folder used to search for paths.
 */
@property (nonatomic, strong) NSString *rootFolderName;

/**
 Shared instance of the ICPBoxSDKHelper.
 
 This helper is configurated with the default BOXContentClient 
 and '<i>DatacapApplications</i>' as root folder name
 
 @return Shared instance of ICPBoxSDKHelper
 */
+ (instancetype) helper;

- (instancetype) init NS_UNAVAILABLE;

/**
 The ICPBoxSDKHelper encapsulate the Box sdk operations 
 
 @param rootFolderName  The name of the configuration root folder. The default is <i>DatacapApplications</i>
 */
- (instancetype) initWithRootFolderName:(NSString *)rootFolderName NS_DESIGNATED_INITIALIZER;

/**
 This method will list the items on the root path of Box and look for the folder set as root for datacap configuration.
 Once the folder is found, the itens on the folder are listed.
 
 @param completion  Block that will be called once that the operation is completed
 */
- (void) findDatacapRootFolderWithCompletion:(ICPBoxHelperRootLookupBlock)completion;

/**
 This method will search for a folder on a given path.
 Once the folder is found, the itens on the folder are listed.
 
 @param folder      Name of the folder that will be searched
 @param folderId    Id of the parent folder where the search will be made
 @param completion  Block that will be called once that the operation is completed
 */
- (void) findFolder:(NSString *)folder
             onPath:(NSString *)folderId
     withCompletion:(ICPBoxHelperRootLookupBlock)completion;

/**
 This method will search for a folder on the datacap configuration root folder.
 Once the folder is found, the itens on the folder are listed.
 
 @param folder      Name of the folder that will be searched
 @param completion  Block that will be called once that the operation is completed
 */
- (void) findFolderOnRoot:(NSString *)folder
           withCompletion:(ICPBoxHelperRootLookupBlock)completion;

/**
 This method will navigate to the datacap configuration root folder and search to the folder
 related to an application.
 
 @param application Name of the application
 @param completion  Block that will be called once that the operation is completed
 */
- (void) navigateToApplication:(NSString *)application
                    andPerform:(ICPBoxHelperNavigationBlock)completion;

/**
 This method will navigate to the datacap configuration root folder and list all its items
 
 @param completion  Block that will be called once that the operation is completed
 */
- (void) listItemsOnRootWithCompletion:(ICPBoxHelperFolderListBlock)completion;

/**
 This method will navigate to a given folder and list all its items
 
 @param folderId    Id of the folder that the items will be listed
 @param completion  Block that will be called once that the operation is completed
 */
- (void) listItemsOnPathWithId:(NSString *)folderId
                withCompletion:(ICPBoxHelperFolderListBlock)completion;

/**
 This method will download the binary content of a specific file
 
 @param fileId      Id of the file that will be downloaded
 @param completion  Block that will be called once that the operation is completed
 */
- (void) downloadFileWithId:(NSString *)fileId
             withCompletion:(ICPBoxHelperDownloadFileBlock)completion;

/**
 This method will create an empty folder on a given folder
 
 @param folderName      Name that will be used to create the folder
 @param parentFolderId  Id of the folder where the desired folder will be created
 @param completion      Block that will be called once that the operation is completed
 */
- (void) createFolderWithName:(NSString *)folderName
         inParentFolderWithId:(NSString *)parentFolderId
                withCompletion:(ICPBoxHelperNavigationBlock)completion;

/**
 This method will delete a specific folder and all its content
 
 @param folderId    Id of the folder that will be deleted
 @param completion  Block that will be called once that the operation is completed
*/
- (void) deleteFolder:(NSString *)folderId
       withCompletion:(ICPBoxHelperOperationBlock)completion;

/**
 This method will create and upload a file to a specific folder
 
 @param file        NSData with the file content
 @param folder      Folder where the file will be created
 @param name        Name that will be used to create the file
 @param progress    Block that will be used to show the upload progress
 @param completion  Block that will be called once that the operation is completed
 */
- (void)uploadFile:(NSData *)file
          onFolder:(NSString *)folder
          withName:(NSString *)name
          progress:(ICPBoxHelperProgressBlock)progress
     andCompletion:(ICPBoxHelperFileUpdateBlock)completion;

/**
 This method will update the content of a specific file
 
 @param fileId      Id of the file that will be updated
 @param data        NSData with the new file content
 @param progress    Block that will be used to show the upload progress
 @param completion  Block that will be called once that the operation is completed
 */
- (void) updateFile:(NSString *)fileId
           withData:(NSData *)data
           progress:(ICPBoxHelperProgressBlock)progress
      andCompletion:(ICPBoxHelperFileUpdateBlock)completion;

@end

NS_ASSUME_NONNULL_END
