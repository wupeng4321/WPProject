//
//  UIView+delay.h
//  button
//
//  Created by wupeng on 2017/6/14.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (delay)

@property (nonatomic, assign) CGFloat delay;

@property (nonatomic, copy) dispatch_block_t oneTapBlock;

@property (nonatomic, assign) BOOL taskShouldBeCanceled;

@end
