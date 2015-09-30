/*
     File: iPhoneGLEssentialPracticesAppDelegate.h
 Abstract: The application delegate.
  Version: 1.0
*/

#import <UIKit/UIKit.h>

@class EAGLView;









@interface iPhoneGLEssentialPracticesAppDelegate : NSObject <UIApplicationDelegate> 
{
        UIWindow *window;
	EAGLView *glView;

        CGRect bounds;

        // Create a view and add it to the window.
        UIView* view;

}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet EAGLView *glView;




@end

