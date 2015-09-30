//
//  TestViewController.m
//
//  Copyright iOSDeveloperTips.com All rights reserved.
//

#import "TestViewController.h"

@implementation TestViewController

- (void)viewDidLoad 
{
  [self setView:[[[UIView alloc] initWithFrame:[[UIScreen mainScreen] applicationFrame]] autorelease]];

	// Create a patterned background
  UIImage *pattern = [UIImage imageNamed:@"background.jpg"];
  [[self view] setBackgroundColor:[UIColor colorWithPatternImage:pattern]];

	// -----------------------------
	// One finger, two taps
	// -----------------------------

	// Create gesture recognizer, notice the selector method
  UITapGestureRecognizer *oneFingerTwoTaps = 
	  [[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(oneFingerTwoTaps)] autorelease];

  // Set required taps and number of touches
  [oneFingerTwoTaps setNumberOfTapsRequired:2];
  [oneFingerTwoTaps setNumberOfTouchesRequired:1];

  // Add the gesture to the view
  [[self view] addGestureRecognizer:oneFingerTwoTaps];

	// -----------------------------
  // Two fingers, two taps
  // -----------------------------
  UITapGestureRecognizer *twoFingersTwoTaps = 
    [[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(twoFingersTwoTaps)] autorelease];
  [twoFingersTwoTaps setNumberOfTapsRequired:2];
  [twoFingersTwoTaps setNumberOfTouchesRequired:2];
  [[self view] addGestureRecognizer:twoFingersTwoTaps];
  
	// -----------------------------
  // One finger, swipe up
	// -----------------------------
  UISwipeGestureRecognizer *oneFingerSwipeUp = 
  	[[[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(oneFingerSwipeUp:)] autorelease];
  [oneFingerSwipeUp setDirection:UISwipeGestureRecognizerDirectionUp];
  [[self view] addGestureRecognizer:oneFingerSwipeUp];

	// -----------------------------
	// One finger, swipe down
	// -----------------------------
  UISwipeGestureRecognizer *oneFingerSwipeDown = 
  	[[[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(oneFingerSwipeDown:)] autorelease];
  [oneFingerSwipeDown setDirection:UISwipeGestureRecognizerDirectionDown];
  [[self view] addGestureRecognizer:oneFingerSwipeDown];

	// -----------------------------
	// Two finger rotate  
	// -----------------------------
	UIRotationGestureRecognizer *twoFingersRotate = 
  	[[[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(twoFingersRotate:)] autorelease];
  [[self view] addGestureRecognizer:twoFingersRotate];

	// -----------------------------
	// Two finger pinch
	// -----------------------------
	UIPinchGestureRecognizer *twoFingerPinch = 
  	[[[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(twoFingerPinch:)] autorelease];
  [[self view] addGestureRecognizer:twoFingerPinch];
  
}

/*--------------------------------------------------------------
* One finger, two taps 
*-------------------------------------------------------------*/
- (void)oneFingerTwoTaps
{
	NSLog(@"Action: One finger, two taps");
}
 
/*--------------------------------------------------------------
* Two fingers, two taps
*-------------------------------------------------------------*/
- (void)twoFingersTwoTaps {
  NSLog(@"Action: Two fingers, two taps");
} 

/*--------------------------------------------------------------
* One finger, swipe up
*-------------------------------------------------------------*/
- (void)oneFingerSwipeUp:(UISwipeGestureRecognizer *)recognizer 
{ 
  CGPoint point = [recognizer locationInView:[self view]];
  NSLog(@"Swipe up - start location: %f,%f", point.x, point.y);
}

/*--------------------------------------------------------------
* One finger, swipe down
*-------------------------------------------------------------*/
- (void)oneFingerSwipeDown:(UISwipeGestureRecognizer *)recognizer 
{ 
  CGPoint point = [recognizer locationInView:[self view]];
  NSLog(@"Swipe down - start location: %f,%f", point.x, point.y);
}

/*--------------------------------------------------------------
* Two finger rotate   
*-------------------------------------------------------------*/
- (void)twoFingersRotate:(UIRotationGestureRecognizer *)recognizer 
{
	// Convert the radian value to show the degree of rotation
	NSLog(@"Rotation in degrees since last change: %f", ([recognizer rotation] * 180) / M_PI);
}

/*--------------------------------------------------------------
* Two finger pinch
*-------------------------------------------------------------*/
- (void)twoFingerPinch:(UIPinchGestureRecognizer *)recognizer 
{
	NSLog(@"Pinch scale: %f", recognizer.scale);
}
  
- (void)dealloc 
{
	[super dealloc];
}

@end
