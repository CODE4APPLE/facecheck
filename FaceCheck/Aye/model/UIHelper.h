//
//  UIHelper.h
//  JSONKitDemo
//
//  Created by apple on 14-4-17.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIHelper : UIView

+(UILabel *)createLabel:(NSString *)text frame:(CGRect)frame textColor:(UIColor *)textColor;

+(UIButton *)createBtn:(NSString *)title titleColor:(UIColor *)titleColor frame:(CGRect)frame btnType:(UIButtonType)btnType selImage:(NSString *)selImage unSelImage:(NSString *)unSelImage target:(id)target action:(SEL)action;

+(UIView *)createView:(CGRect)frame;

+(UIImageView *)createImageView:(NSString *)image frame:(CGRect)frame;

+(UITextField *)createTextField:(NSString *)text frame:(CGRect)frame placeholder:(NSString *)placeholder target:(id)target;


+(UIColor *) hexStringToColor: (NSString *) stringToConvert; 
@end


@interface ChangeColor : NSObject

+(UIColor *) hexStringToColor: (NSString *) stringToConvert;

@end


@interface UIButton(Additions)

+ (UIButton *)buttonWithFrame:(CGRect)frame title:(NSString *)title titleColor:(UIColor *)titlecolor target:(id)target action:(SEL)action;
+ (UIButton *)buttonWithType:(UIButtonType)buttonType frame:(CGRect)frame title:(NSString *)title backgroundImage:(UIImage *)backgroundImage target:(id)target action:(SEL)action;

@end

@interface UIImageView(Additions)

+ (UIImageView *)imageViewWithFrame:(CGRect)frame image:(UIImage *)image userInteractionEnabled:(BOOL)userInteractionEnabled;

@end

