//
// Created by Boojapathy Chidambaram on 8/27/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FlexContainerViewController.h"

@protocol FlexSideMenuDelegate;
@class FlexSideMenuAnimator;

enum FlexMenuPosition {
    Right,
    Left
};

@interface FlexSideMenu : UIViewController <UIGestureRecognizerDelegate>
@property (assign, nonatomic) BOOL usesAutoLayout;

@property(nonatomic, assign) BOOL isMenuVisible;
@property (weak, nonatomic) UIViewController * statusBarStyleController;
@property(nonatomic, assign) id<FlexSideMenuDelegate> delegate;

@property(nonatomic, readonly) UIScreenEdgePanGestureRecognizer *leftEdgePanRecognizer;
@property(nonatomic, readonly) UIPanGestureRecognizer *panGesture;
@property(nonatomic, readonly) UITapGestureRecognizer *tapGesture;

+ (void)registerAnimation:(Class)sideMenuAnimation;

- (instancetype)initWithContentViewController:(UIViewController *)contentViewController leftSideMenuController:(UIViewController *)leftSideMenuController rightSideMenuController:(UIViewController *)rightSideMenuController usesAutoLayout:(BOOL)usesAutoLayout animator:(FlexSideMenuAnimator *)animator;

- (void)toggleLeftMenu;

- (void)hideSidebarViewController:(void (^)(void))onCompletion;

- (UIViewController *)leftMenuController;

- (UIViewController *)contentController;

- (void)setContentController:(UIViewController *)newContentController;

@end

@interface UIViewController(FlexSideMenu)

@property (strong, readonly, nonatomic) FlexSideMenu *sideMenu;

@end
