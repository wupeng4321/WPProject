//
//  WPTabBarViewController.m
//  FullScreenPop
//
//  Created by wupeng on 2017/9/6.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#import "WPTabBarViewController.h"


@interface WPTabBarViewController ()

@end

@implementation WPTabBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

/**
 set up child view controller

 @param childVC child view controller
 @param title title
 @param normalImageName normal image
 @param selectedImageName selected image name
 @param normalAttributes normal text attributes
 @param selectedAttributes selected text attributes
 */
- (void)setUpChildViewController:(UIViewController *)childVC
                           title:(NSString *)title
                       imageName:(NSString *)normalImageName
               selectedImageName:(NSString *)selectedImageName
       normalTitleTextAttributes:(NSDictionary *)normalAttributes
     selectedTitleTextAttributes:(NSDictionary *)selectedAttributes {
    
    childVC.tabBarItem.title         = title;
    
    childVC.tabBarItem.image         = [[UIImage imageNamed:normalImageName] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childVC.tabBarItem.selectedImage = [[UIImage imageNamed:selectedImageName] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    
    [childVC.tabBarItem setTitleTextAttributes:normalAttributes forState:UIControlStateNormal];
    [childVC.tabBarItem setTitleTextAttributes:selectedAttributes forState:UIControlStateSelected];
    [childVC.tabBarItem setImageInsets:UIEdgeInsetsMake(0, 0, 0, 0)];
}
@end
