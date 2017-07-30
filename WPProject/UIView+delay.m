//
//  UIView+delay.m
//  button
//
//  Created by wupeng on 2017/6/14.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#import "UIView+delay.h"
#import <objc/runtime.h>
static const void *DelayKey = @"DelayKey";

@implementation UIView (delay)

- (void)setDelay:(CGFloat)delay {
    NSNumber *delayValue = delay ? @(delay) : nil;

    objc_setAssociatedObject(self, DelayKey, delayValue, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

}

- (CGFloat)delay {
    return [objc_getAssociatedObject(self, DelayKey) floatValue];
}

- (void)setOneTapBlock:(dispatch_block_t)oneTapBlock{
    oneTapBlock();
    self.taskShouldBeCanceled = YES;
}

- (dispatch_block_t)oneTapBlock{
    return self.oneTapBlock;
}

- (void)setTaskShouldBeCanceled:(BOOL)taskShouldBeCanceled{
    objc_setAssociatedObject(self, @"taskShouldBeCanceled", @(!taskShouldBeCanceled), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (BOOL)taskShouldBeCanceled{
    return [objc_getAssociatedObject(self, @"taskShouldBeCanceled") boolValue];
}


@end
