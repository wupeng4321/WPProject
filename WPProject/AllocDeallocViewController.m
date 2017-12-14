//
//  AllocDeallocViewController.m
//  testSec
//
//  Created by wupeng on 2017/12/13.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#import "AllocDeallocViewController.h"

@interface AllocDeallocViewController ()

@end

@implementation AllocDeallocViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

#ifdef DEBUG
    static NSMutableDictionary *s_allocInfo;
#endif


#pragma mark - init and dealloc

- (instancetype)init {
    if (self == [super init]) {
        [self allocInit];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    if (self == [super initWithCoder:aDecoder]) {
        [self allocInit];
    }
    return self;
}

- (void)allocInit {
#ifdef DEBUG
    NSLog(@"----------------创建类----------------%@", NSStringFromClass([self class]));
    if (!s_allocInfo) {
        s_allocInfo = [NSMutableDictionary dictionary];
    }

    s_allocInfo[NSStringFromClass([self class])] = @([s_allocInfo[NSStringFromClass([self class])] intValue] + 1);
    NSLog(@"%@", s_allocInfo);
#endif
}

- (void)dealloc {
    
    #ifdef DEBUG
        NSLog(@"----------------释放类----------------%@",  NSStringFromClass([self class]));
    
        s_allocInfo[NSStringFromClass([self class])] = @([s_allocInfo[NSStringFromClass([self class])] intValue] - 1);
        if ([s_allocInfo[NSStringFromClass([self class])] intValue] == 0) {
            [s_allocInfo removeObjectForKey:NSStringFromClass([self class])];
        }
        NSLog(@"%@", s_allocInfo);
    #endif
        [[NSNotificationCenter defaultCenter] removeObserver:self];
}


@end
