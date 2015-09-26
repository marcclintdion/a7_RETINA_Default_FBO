//
//  ViewController.m
//  openGL_startup
//
//  Created by marc  dion on 13-05-19.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//



#import "ViewController.h"

CGImageRef spriteImage;
size_t width;
size_t height;
GLubyte * spriteData;
CGContextRef spriteContext;


#import "../RunGL.cpp"



//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================


@interface ViewController () 
{

}
@property (strong, nonatomic) EAGLContext *context;


- (void)tearDownGL;


@end

@implementation ViewController

@synthesize context = _context;


//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2] autorelease];

    if (!self.context) 
    {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    //view.drawableMultisample = GLKViewDrawableMultisample4X;
    view.drawableMultisample = GLKViewDrawableMultisampleNone;
       
        self.preferredFramesPerSecond = 120;    
        
        CGRect screenBounds     = [[UIScreen mainScreen] bounds];
        CGFloat screenScale     = [[UIScreen mainScreen] scale];        
        //CGSize  screenSize    = CGSizeMake(screenBounds.size.width * screenScale, screenBounds.size.height * screenScale);        
        
        viewHeight              = screenBounds.size.width  * screenScale;
        viewWidth               = screenBounds.size.height * screenScale;
        
        
        NSLog(@"viewWidth: %i", viewWidth); 
        NSLog(@"viewHeight: %i", viewHeight);     
        
        
        [EAGLContext setCurrentContext:self.context];
        
        glEnable(GL_DEPTH_TEST);
        
        InitGL();
}



//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================



- (BOOL)shouldAutorotateToInterfaceOrientation: (UIInterfaceOrientation)interfaceOrientation 
{
        return (interfaceOrientation == UIInterfaceOrientationLandscapeRight);
}

//============================================================================================

/*
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
                return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
        } else {
                return YES;
        }
} */

//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================


- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
        
        [((GLKView *) self.view) bindDrawable];  // return to iOS default framebuffer
    

        RenderGL();   
        
        
        [((GLKView *) self.view) bindDrawable];  // return to iOS default framebuffer        
}

//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event 
{
        goldenSunset_LIGHT_POSITION_01[3] += 1;
        
        NSLog(@"goldenSunset_LIGHT_POSITION_01[3]: %f", goldenSunset_LIGHT_POSITION_01[3]); 
        
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event 
{
        //goldenSunset_LIGHT_POSITION_01[3] += 1;
}

//================================================================================================================================================
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
//================================================================================================================================================


- (void)viewDidUnload
{    
        [super viewDidUnload];
        
        [self tearDownGL];
        
        if ([EAGLContext currentContext] == self.context) 
        {
                [EAGLContext setCurrentContext:nil];
        }
        self.context = nil;
}

- (void)didReceiveMemoryWarning
{
        [super didReceiveMemoryWarning];
        // Release any cached data, images, etc. that aren't in use.
}

- (void)tearDownGL
{
        [EAGLContext setCurrentContext:self.context];
        
        ShutDownGL();
}

- (void)dealloc
{
        [_context release];

        [super dealloc];
}




@end
