//
//  ViewController.m
//  FaceCheck
//
//  Created by linyingwei on 16/5/4.
//  Copyright © 2016年 linyingwei. All rights reserved.
//

#import "ViewController.h"
#import "ApprovedViewController.h"
@interface ViewController ()<getAliveDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}
- (IBAction)startAction:(UIButton *)sender {
    ApprovedViewController *avc = [[ApprovedViewController alloc]init];
    avc.timeOUT = 30;
    avc.number = 10;
    avc.timesTap = @"20160504094318";
    avc.showbackbtn = 1;
    avc.delegate = self;
    avc.mypath0 = [[NSBundle mainBundle]bundlePath];
    [self.navigationController pushViewController:avc animated:YES];
}

-(NSString*)getAlive:(NSString *)alive
{
     if([alive isEqualToString:@"-10"]){
        //第一次设备检测的回调值，无响应动作
    }
    else if([alive isEqualToString:@"0"]){
        [self initAlertViewWith:@"成功了"];
    }else{
        [self initAlertViewWith:@"失败了"];
    }
    return alive;
}

- (void)initAlertViewWith:(NSString*)msg{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:msg preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self.navigationController popViewControllerAnimated:YES];
    }];
    [alert addAction:action];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
