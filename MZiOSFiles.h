#import <Foundation/Foundation.h>

@interface MZiOSFiles : NSObject

+(bool)isFileExistWithPath:(NSString* )path;
+(bool)isFileExistInBundleWithName:(NSString* )name;
+(bool)isFileExistInDocumentsWithName:(NSString* )name;

+(NSString* )bundlePath;
+(NSString* )documentsPath;

+(NSString* )filePathFromDocumentsWithName:(NSString *)name;
+(NSString* )filePathFromBundleWithName:(NSString *)name;

// simulator is ok, not test in device ...
+(NSArray* )contentURLsInDirectory:(NSString *)directoryPath;

+(NSDictionary* )plistContentFromBundleWithName:(NSString *)name;
+(NSDictionary *)plistContentFromDocumentsWithName:(NSString *)name;

+(NSError* )copyFileFromBundleToDocumentsWithName:(NSString* )name removeExist:(bool)removeExist;
+(NSError* )saveFileToDocumentsWithName:(NSString* )fileName file:(NSObject* )file removeExist:(bool)removeExist;
@end
