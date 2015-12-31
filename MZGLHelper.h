#import <OpenGLES/ES2/gl.h>

@interface MZGLHelper : NSObject
+(GLenum)glBlendEnumFromString:(NSString *)enumString;
+(GLenum)defaultBlendFuncSrc;
+(GLenum)defaultBlendFuncDest;
@end


