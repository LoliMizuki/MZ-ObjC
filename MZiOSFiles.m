#import "MZiOSFiles.h"
#import "MZLogs.h"

@implementation MZiOSFiles

+(bool)isFileExistWithPath:(NSString* )path {
    return [[NSFileManager defaultManager] fileExistsAtPath: path];
}

+(bool)isFileExistInBundleWithName:(NSString* )name {
   return [MZiOSFiles isFileExistWithPath: [MZiOSFiles filePathFromBundleWithName: name]];
}

+(bool)isFileExistInDocumentsWithName:(NSString* )name {
   return [MZiOSFiles isFileExistWithPath: [MZiOSFiles filePathFromDocumentsWithName: name]];
}

+(NSString* )bundlePath {
    return [[NSBundle mainBundle] bundlePath];
}

+(NSString* )documentsPath {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return [paths firstObject];
}

+(NSString* )filePathFromDocumentsWithName:(NSString *)name {
    return [[MZiOSFiles documentsPath] stringByAppendingPathComponent: name];
}

+(NSString* )filePathFromBundleWithName:(NSString *)name {
    return [[MZiOSFiles bundlePath] stringByAppendingPathComponent: name];
}

+(NSArray* )contentURLsInDirectory:(NSString *)directoryPath {
    NSURL* url = [NSURL fileURLWithPath:directoryPath];

    NSError *error = nil;
    NSFileManager* fileManager = [NSFileManager defaultManager];
    NSArray* contentURLs = [fileManager contentsOfDirectoryAtURL:url
                                      includingPropertiesForKeys:@[]
                                                         options:NSDirectoryEnumerationSkipsHiddenFiles error:&error];

    if(error != nil) {
        return nil;
    }

    return contentURLs;
}

+(NSDictionary* )plistContentFromBundleWithName:(NSString *)name {
    NSString* fullPath = [MZiOSFiles filePathFromBundleWithName: name];
    if( [MZiOSFiles isFileExistWithPath: fullPath] == false ) return nil;

    NSDictionary *plistContent = [NSDictionary dictionaryWithContentsOfFile: fullPath];
    
	return plistContent;
}

+(NSDictionary* )plistContentFromDocumentsWithName:(NSString *)name {
    NSString *fullPath = [MZiOSFiles filePathFromDocumentsWithName: name];
    if( [MZiOSFiles isFileExistWithPath: fullPath] == false ) return nil;

    NSDictionary *plistContent = [NSDictionary dictionaryWithContentsOfFile: fullPath];

    return plistContent;
}

+(NSError* )copyFileFromBundleToDocumentsWithName:(NSString* )name removeExist:(bool)removeExist {
    NSError* error = nil;

    NSString* srcPath = [MZiOSFiles filePathFromBundleWithName: name];
    NSString* dstPath = [MZiOSFiles filePathFromDocumentsWithName: name];

    if(removeExist && [MZiOSFiles isFileExistWithPath: dstPath]) {
        [[NSFileManager defaultManager] removeItemAtPath: dstPath error: &error];
        if(error != nil) {
            return error;
        }
    }

    [[NSFileManager defaultManager] copyItemAtPath: srcPath
                                            toPath: dstPath
                                             error: &error];
    return error;
}

+(NSError* )saveFileToDocumentsWithName:(NSString* )fileName file:(NSObject* )file removeExist:(bool)removeExist {
    if(fileName == nil) {
        return [NSError errorWithDomain: NSPOSIXErrorDomain
                                   code: 401
                               userInfo: @{NSLocalizedDescriptionKey: @"file name is nil"}];
    }

    if(file == nil) {
        return [NSError errorWithDomain: NSPOSIXErrorDomain
                                   code: 401
                               userInfo: @{NSLocalizedDescriptionKey: @"file is nil"}];
    }

    NSString *filePath = [MZiOSFiles filePathFromDocumentsWithName: fileName];
    
    if(removeExist && [MZiOSFiles isFileExistWithPath: filePath]) {
        NSError *error = nil;
        [[NSFileManager defaultManager] removeItemAtPath: filePath error: &error];

        if(error != nil) return error;
    }

    if([file respondsToSelector: @selector(writeToFile:atomically:)] == false) {
        return [NSError errorWithDomain: NSPOSIXErrorDomain
                                   code: 401
                               userInfo: @{NSLocalizedDescriptionKey: @"file object not have writeToFile:atomically:"}];
    }

    [file performSelector: @selector(writeToFile: atomically:) withObject: filePath withObject: 0];
    
    return nil;
}

@end