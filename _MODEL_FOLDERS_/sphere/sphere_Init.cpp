

//================================================================================================================================================
spriteImage          = [UIImage imageNamed:@"sphere_DOT3.bmp"].CGImage;
width                    =  CGImageGetWidth(spriteImage);
height                   =  CGImageGetHeight(spriteImage);
spriteData            = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
spriteContext      =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);    
CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
CGContextRelease(spriteContext);
//-----------------------------------------------------------------------------------------------------
glGenTextures(1, &sphere_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, sphere_NORMALMAP);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);

if(spriteData != NULL)
{
        free(spriteData);    
} 
//=====================================================================================================
spriteImage          = [UIImage imageNamed:@"sphere.png"].CGImage;
width                    =  CGImageGetWidth(spriteImage);
height                   =  CGImageGetHeight(spriteImage);
spriteData            = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
spriteContext      =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);    
CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
CGContextRelease(spriteContext);
//-----------------------------------------------------------------------------------------------------
glGenTextures(1, &sphere_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, sphere_TEXTUREMAP);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);

if(spriteData != NULL)
{
        free(spriteData);    
} 
//================================================================================================================================================


#include    "sphere.cpp"                                                                                                                
glGenBuffers(1,              &sphere_VBO);                                                                                                
glBindBuffer(GL_ARRAY_BUFFER, sphere_VBO);                                                                                                
glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);                                                                    
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
//------------------------------------------------------------------------------------------------------------//___LOAD_INDEX_VBO          
#include    "sphere_INDEX.cpp"       
glGenBuffers(1, &sphere_INDEX_VBO);                       
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphere_INDEX_VBO);                   
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sphere_INDEX), sphere_INDEX, GL_STATIC_DRAW);
//=================================================================================================================================   
