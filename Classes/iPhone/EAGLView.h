/*
     File: EAGLView.h
 Abstract: The EAGLView class is a UIView subclass that renders OpenGL scene.
  Version: 1.0
*/

#import <UIKit/UIKit.h>

#import "ES2Renderer.h"



#import "iPhoneGLEssentialsAppDelegate.h"

// This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
// The view content is basically an EAGL surface you render your OpenGL scene into.
// Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
@interface EAGLView : UIView
{    
   
@private
	ES2Renderer* renderer;
	
	EAGLContext *_context;
	
	BOOL animating;
	BOOL displayLinkSupported;
	NSInteger animationFrameInterval;
	id displayLink;
    NSTimer *animationTimer;
}

@property (readonly, nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;



//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================



- (void) startAnimation;
- (void) stopAnimation;
- (void) drawView:(id)sender;



@end
