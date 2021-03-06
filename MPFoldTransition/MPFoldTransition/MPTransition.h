//
//  MPTransition.h
//  MPFoldTransition (v1.0.2)
//
//  Created by Mark Pospesel on 5/14/12.
//  Copyright (c) 2012 Mark Pospesel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MPTransitionEnumerations.h"

typedef void (^CompletionBlock)(BOOL);


@interface MPTransition : NSObject

#pragma mark - Properties

@property (retain, nonatomic) UIView *superview;
@property (retain, nonatomic) UIView *sourceView;
@property (retain, nonatomic) UIView *destinationView;
@property (assign, nonatomic) NSTimeInterval duration;
@property (assign, nonatomic) CGRect rect;
@property (assign, nonatomic) MPTransitionAction completionAction;
@property (assign, nonatomic) UIViewAnimationCurve timingCurve;
// Perspective component of transformation (Advanced use only, generally don't need to adjust)
@property (assign, nonatomic) float m34;

// Special case of dismissing a modal view
@property (assign, nonatomic, getter = isDimissing) BOOL dismissing;

#pragma mark - init

- (id)initWithSourceView:(UIView *)sourceView destinationView:(UIView *)destinationView duration:(NSTimeInterval)duration timingCurve:(UIViewAnimationCurve)timingCurve completionAction:(MPTransitionAction)action;

#pragma mark - Instance methods

- (void)perform;
- (void)perform:(void (^)(BOOL finished))completion;

- (NSString *)timingCurveFunctionName;
- (void)transitionDidComplete;
- (void)setPresentingController:(UIViewController *)presentingController;

#pragma mark - Class methods

+ (NSTimeInterval)defaultDuration;

@end
