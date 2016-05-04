//
//  UIHelper.m
//  JSONKitDemo
//
//  Created by apple on 14-4-17.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//

#import "UIHelper.h"

@implementation UIHelper

+(UILabel *)createLabel:(NSString *)text frame:(CGRect)frame textColor:(UIColor *)textColor;
{
    UILabel *label=[[UILabel alloc]initWithFrame:frame];
    label.text=text;
    label.textColor=textColor;
    label.backgroundColor = [UIColor clearColor];
    return label;
}

+(UIButton *)createBtn:(NSString *)title titleColor:(UIColor *)titleColor frame:(CGRect)frame btnType:(UIButtonType)btnType selImage:(NSString *)selImage unSelImage:(NSString *)unSelImage target:(id)target action:(SEL)action
{
    UIButton *btn=[UIButton buttonWithType:btnType];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:titleColor forState:UIControlStateNormal];
    btn.frame=frame;
    [btn setBackgroundImage:[UIImage imageNamed:unSelImage] forState:UIControlStateNormal];
    [btn setBackgroundImage:[UIImage imageNamed:selImage] forState:UIControlStateHighlighted];
    [btn addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return btn;
}

+(UIView *)createView:(CGRect)frame
{
    UIView *bgView=[[UIView alloc]initWithFrame:frame];
    return bgView;
}

+(UIImageView *)createImageView:(NSString *)image frame:(CGRect)frame
{
    UIImageView *imageView=[[UIImageView alloc]initWithFrame:frame];
    imageView.image=[UIImage imageNamed:image];
    return imageView;
}

+(UITextField *)createTextField:(NSString *)text frame:(CGRect)frame placeholder:(NSString *)placeholder target:(id)target
{
    UITextField *textField=[[UITextField alloc]initWithFrame:frame];
    textField.text=text;
    textField.placeholder=placeholder;
    textField.delegate=target;
    return textField;
}
@end

@implementation ChangeColor

+(UIColor *) hexStringToColor: (NSString *) stringToConvert
{
    NSString *cString = [[stringToConvert stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    // String should be 6 or 8 charactersif ([cString length] < 6) return [UIColor blackColor];
    // strip 0X if it appearsif ([cString hasPrefix:@"0X"]) cString = [cString substringFromIndex:2];
    if ([cString hasPrefix:@"#"]) cString = [cString substringFromIndex:1];
    if ([cString length] != 6) return [UIColor blackColor];
    
    // Separate into r, g, b substrings
    NSRange range;
    range.location = 0;
    range.length = 2;
    NSString *rString = [cString substringWithRange:range];
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    // Scan values
    unsigned int r, g, b;
    
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f)
                           green:((float) g / 255.0f)
                            blue:((float) b / 255.0f)
                           alpha:1.0f];
}


@end


@implementation UIButton(Additions)

+ (UIButton *)buttonWithFrame:(CGRect)frame title:(NSString *)title titleColor:(UIColor *)titlecolor target:(id)target action:(SEL)action
{
    UIButton * button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.frame = frame;
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitleColor:titlecolor forState:UIControlStateNormal];
    [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
}
+ (UIButton *)buttonWithType:(UIButtonType)buttonType frame:(CGRect)frame title:(NSString *)title backgroundImage:(UIImage *)backgroundImage target:(id)target action:(SEL)action
{
    UIButton * button = [UIButton buttonWithType:buttonType];
    button.frame = frame;
    [button setTitle:title forState:UIControlStateNormal];
    [button setBackgroundImage:backgroundImage forState:UIControlStateNormal];
    [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
    
}

@end




@implementation UIImageView(Additions)

+ (UIImageView *)imageViewWithFrame:(CGRect)frame image:(UIImage *)image userInteractionEnabled:(BOOL)userInteractionEnabled
{
    UIImageView * imageView = [[UIImageView alloc] initWithFrame:frame];
    imageView.image = image;
    imageView.userInteractionEnabled = userInteractionEnabled;
    return imageView;
}

@end

