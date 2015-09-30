/*
     File: ES2Renderer.m
 Abstract: The ES2Renderer class creates an OpenGL ES 2.0 context and delegates to its super class, OpenGLRenderer, for creating and drawing the shaders.
  Version: 1.0
*/

//###################################################################################################################################################################
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>



#import "imageUtil.h"

EAGLContext *_context;

//=====================================
CGImageRef spriteImage;
size_t width;
size_t height;
GLubyte * spriteData;
CGContextRef spriteContext;
//=====================================
demoImage *image;
NSString* filePathName = nil;



#include "../../RunGL.cpp"



#import "ES2Renderer.h"



@interface ES2Renderer (PrivateMethods)

@end


EAGLContext * _context;




GLuint viewRenderbuffer;
GLuint depthRenderbuffer;
GLuint msaaFramebuffer, msaaRenderBuffer, msaaDepthBuffer;

@implementation ES2Renderer




//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

// Create an ES 2.0 context
- (ES2Renderer* ) initWithContext:(EAGLContext *) context AndDrawable:(id<EAGLDrawable>)drawable
{	
    _context = context;
    //=============================================================================================================================    
    glGenFramebuffers(1, &viewFramebuffer);
    glGenRenderbuffers(1, &viewRenderbuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, viewFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer);
	
    [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:drawable];
	
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, viewRenderbuffer);

    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
    //-------------------------------------------------------------------------------------------------
    glGenRenderbuffers(1, &depthRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24_OES, backingWidth, backingHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);
    //=============================================================================================================================
    //Generate our MSAA Frame and Render buffers
    glGenFramebuffers(1, &msaaFramebuffer);
    glGenRenderbuffers(1, &msaaRenderBuffer);
    
    //Bind our MSAA buffers
    glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, msaaRenderBuffer);
    
    // Generate the msaaDepthBuffer.
    // 4 will be the number of pixels that the MSAA buffer will use in order to make one pixel on the render buffer.
    glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, backingWidth, backingHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, msaaRenderBuffer);
    
    glGenRenderbuffers(1, &msaaDepthBuffer); 
    glBindRenderbuffer(GL_RENDERBUFFER, msaaDepthBuffer);
    glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT24_OES, backingWidth , backingHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, msaaDepthBuffer);
    

    InitGL();
    


	
	//self = [super initWithDefaultFBO:viewFramebuffer];
	

	
	return self;
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void)render 
{
        // Replace the implementation of this method to do your own custom drawing

    

    
        RenderGL();	    

        //===============================================================================================================================================
        //----------------------------------------------------------------Bind both MSAA and View FrameBuffers. 
        glBindFramebuffer(GL_READ_FRAMEBUFFER_APPLE, msaaFramebuffer); 
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER_APPLE, viewFramebuffer);   
        glResolveMultisampleFramebufferAPPLE();   
        //--------------------------------------------------------------------
        const GLenum discards[]  = {GL_COLOR_ATTACHMENT0,GL_DEPTH_ATTACHMENT};
        glDiscardFramebufferEXT(GL_READ_FRAMEBUFFER_APPLE,2,discards);        
        //===============================================================================================================================================    
        glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer); 
        [_context presentRenderbuffer:GL_RENDERBUFFER];    
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (BOOL) resizeFromLayer:(CAEAGLLayer *)layer
{
	// The pixel dimensions of the CAEAGLLayer
	GLint backingWidth;
	GLint backingHeight;
        //-------------------------------------------------------------------------------------------------
        // Allocate color buffer backing based on the current layer size
        glBindRenderbuffer(GL_RENDERBUFFER, viewRenderbuffer);
        [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
	
	glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24_OES, backingWidth, backingHeight);
	//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);
	//-------------------------------------------------------------------------------------------------
/*
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, msaaRenderBuffer);
        
        // Generate the msaaDepthBuffer.
        // 4 will be the number of pixels that the MSAA buffer will use in order to make one pixel on the render buffer.
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, backingWidth, backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, msaaRenderBuffer);
        
        glGenRenderbuffers(1, &msaaDepthBuffer); 
        glBindRenderbuffer(GL_RENDERBUFFER, msaaDepthBuffer);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT24_OES, backingWidth , backingHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, msaaDepthBuffer);
	//-------------------------------------------------------------------------------------------------
*/
        //-------------------------------------------------------------------------------------------------------------
	glViewport(0, 0, backingWidth, backingHeight);
	
	viewWidth  = backingWidth;
	viewHeight = backingHeight;
	

    return YES;
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================

- (void) dealloc
{
    
        shutDownGL();
    
    
	if (viewFramebuffer)
	{
		glDeleteFramebuffers(1, &viewFramebuffer);
		viewFramebuffer = 0;
	}
        if (viewRenderbuffer)
	{
		glDeleteRenderbuffers(1, &viewRenderbuffer);
		viewRenderbuffer = 0;
	}
	if (msaaFramebuffer)
	{
		glDeleteFramebuffers(1, &msaaFramebuffer);
		msaaFramebuffer = 0;
	}
        if (msaaRenderBuffer)
	{
		glDeleteRenderbuffers(1, &msaaRenderBuffer);
		msaaRenderBuffer = 0;
	}    
    
    
        [super dealloc];
}

//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




@end






