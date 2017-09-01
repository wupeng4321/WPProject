//
//  Header.h
//  WPProject
//
//  Created by wupeng on 2016/9/1.
//  Copyright © 2017年 wupeng. All rights reserved.
//

#ifndef Header_h
#define Header_h

/**
 * Project Common Macro
 */

/*************************************--Utills--************************************************/

/*example
 *   WS(weakSelf);
 *   [view mas_remakeConstraints:^(MASConstraintMaker *make) {
 *       make.left.equalTo(weakSelf.view.mas_left).offset(100);
 *   }];
 */
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self;

/*example
 *   weakSelf(self);
 *   [view mas_remakeConstraints:^(MASConstraintMaker *make) {
 *       strongSelf(self);
 *       make.left.equalTo(self.view.mas_left).offset(100);
 *   }];
 */
#define weakSelf(type)                  __weak typeof(type) weak##type = type;
#define strongSelf(type)                __strong typeof(type) type = weak##type;

#ifdef DEBUG
    #define DevLog(xx, ...)             NSLog(@"%s(%d):\n\t* " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
    #define DevLog(xx, ...)             ((void)0)
#endif

#define kStrHasValue(str)               (str && [str isKindOfClass:[NSString class]] && [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]].length > 0)

#define kReplaceWithEmptySpaceIfNull(str) kStrHasValue(str) ? str : @""

/*************************************--Color Tool--*********************************************/

#define kClearColor                      [UIColor clearColor]

#define kColor(r, g, b)                  [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kColorA(r, g, b ,a)              [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

#define kColorFromRGB(rgbValue)        [UIColor \
                                        colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                                        green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
                                        blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define kColorFromRGBA(rgbValue,a)     [UIColor \
                                            colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                                            green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
                                            blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]

#define kRandomColor                     [UIColor \
                                            colorWithRed:arc4random_uniform(256)/255.0 \
                                            green:arc4random_uniform(256)/255.0 \
                                            blue:arc4random_uniform(256)/255.0 alpha:1.0]

/**********************************--Screen Size and Device Version--**************************/

#define kScreenHeight                   [UIScreen mainScreen].bounds.size.height

#define kScreenWidth                    [UIScreen mainScreen].bounds.size.width

#define kScreenSize                     [UIScreen mainScreen].bounds.size

#define kDeviceScaleFactor              (kScreenWidth/375.0)

#define kKeyWindow                     [UIApplication sharedApplication].keyWindow

#define iPhone4S                        ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
                                            CGSizeEqualToSize(CGSizeMake(640, 960), \
                                            [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone5                         ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? \
                                            CGSizeEqualToSize(CGSizeMake(640, 1136), \
                                            [[UIScreen mainScreen] currentMode].size) : NO)

#define kScreenIphone6                  (([[UIScreen mainScreen] bounds].size.width)>=375)


#define iPhone5Padding                  ((fabs((double)[[UIScreen mainScreen ]bounds].size.height - (double)568 ) < DBL_EPSILON ) ?88:0)

#define IOS6                            ([[[UIDevice currentDevice] systemVersion] \
                                            compare:@"6.0" options:NSNumericSearch] != NSOrderedAscending)

#define IOS7_OR_LATER                   ([[[UIDevice currentDevice] systemVersion] \
                                            compare:@"7.0" options:NSNumericSearch] != NSOrderedAscending)

#define IOS8_OR_LATER                   ([[[UIDevice currentDevice] systemVersion] \
                                            compare:@"8.0" options:NSNumericSearch] != NSOrderedAscending)

#define IOS7_OR_Later_VIEW_OFFSET       (IOS7_OR_LATER?64:0)

#define iOS7                            ([[[UIDevice currentDevice] systemVersion] doubleValue]>=7.0 ? YES : NO)

#define NLSystemVersionGreaterOrEqualThan(version) \
([[[UIDevice currentDevice] systemVersion] floatValue] >= version)

#define IOS9                            NLSystemVersionGreaterOrEqualThan(9.0)


#define kAppVersion                     [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]


/*************************************--Document Folder--**************************/

#define kPathTemp                       NSTemporaryDirectory()


#define kPathDocument                   [NSSearchPathForDirectoriesInDomains\
                                            (NSDocumentDirectory, NSUserDomainMask, YES) firstObject]


#define kPathCache                      [NSSearchPathForDirectoriesInDomains\
                                            (NSCachesDirectory, NSUserDomainMask, YES) firstObject]

/***************************************--GCD--***********************************/

#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);


#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);


#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlock);

/***************************************--Others--***********************************/

#define kGetImage(imageName)             [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define kNotificationCenter             [NSNotificationCenter defaultCenter]

#define kViewBorderRadius(View, Radius, Width, Color)\
                                        [View.layer setCornerRadius:(Radius)];\
                                        [View.layer setMasksToBounds:YES];\
                                        [View.layer setBorderWidth:(Width)];\
                                        [View.layer setBorderColor:[Color CGColor]]

#define kWindow                         [UIApplication sharedApplication].keyWindow
#define kDegreesToRadian(x)            (M_PI * (x) / 180.0)
#define kRadianToDegrees(radian)       (radian * 180.0) / (M_PI)

#endif /* Header_h */


