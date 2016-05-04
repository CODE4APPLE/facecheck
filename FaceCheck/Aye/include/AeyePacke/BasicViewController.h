//
//  BasicViewController.h
//  医药通
//
//  Created by apple on 14-4-24.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface BasicViewController : UIViewController
{
//    AppDelegate *appDelegate;

    NSString *system_aaa666;
  

}

-(void)loginOut;

-(void)changeSystem_aaa666:(NSString *)system;
-(id)getSystem_aaa666;

- (BOOL) canMakePhoneCalls;
-(BOOL) isValidateMobile:(NSString *)mobile;

//-(void)alertForRequestFailed;//网络不好的提醒
-(NSString*)myWrong:(NSString*)wrong;
@end
