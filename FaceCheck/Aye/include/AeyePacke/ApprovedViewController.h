//
//  ApprovedViewController.h
//  FaceCheck
//
//  Created by apple on 14-7-8.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//
#import <UIKit/UIKit.h>

#import "UIImage+fixOrientation.h"
#import "UIImage+Scale.h"
#import <AVFoundation/AVFoundation.h>
#import"BasicViewController.h"
#import "AEyeBaseFaceStruct.h"
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define winsizeH [[UIScreen mainScreen] bounds].size.height
#define winsizeW  [[UIScreen mainScreen] bounds].size.width
#define iOS7 (([[[UIDevice currentDevice]systemVersion] floatValue] >= 7.0)?YES:NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

@protocol getAliveDelegate <NSObject>
-(NSString*)getAlive:(NSString*)alive;//活体结果
//-(NSString*)getBaoWen:(NSString *)baowen;
@end

@interface ApprovedViewController : BasicViewController<AVCaptureVideoDataOutputSampleBufferDelegate,UIAlertViewDelegate>
{
    AVCaptureSession *_session;
    AVCaptureDeviceInput *_captureInput;
    AVCaptureStillImageOutput *_captureOutput;
    AVCaptureVideoPreviewLayer *_preview;
    AVCaptureDevice *_device;
    dispatch_queue_t queue;
    
    
    
    int imageIndex_;
    NSInteger answer_;
    
    unsigned char* pPreImgData;
    unsigned char* pProcImglx;
    unsigned char* pProcImgRec;
    unsigned char*pProcImgDHQ;//新的归一化
    
    int postImageIndex_;
    NSString* date3;
    NSTimer *timer_;//time out
    
    //    BOOL first_check_pass;
    BOOL first_live_pass;//活体成功，控制不走了
    BOOL check_pass;
    BOOL live_pass;
    
    BOOL alertshow;
    BOOL first_check;//all of checks:pass and no pass
    BOOL appeal_y;//appeal status
    //    BOOL noagain_check;//pop to witch page; 根据用户选择是否重新认证
    
    BOOL end_postin;//control 0607 answer just do once upload
    BOOL unite_feature_post;//control 022510 answer just do once upload
    int TimeOutIndex;
    int reStartTimes;
    
    //    BOOL oneTimeGetAnswer;//记录是否有一次网络请求成功
    //    int live_native_unpass;//本地活体失败次数，本地限制连续失败2次，重启流程
    
    
    //    float score;
    //    float score_parameterline;// min_score 可见光认证阔值
    //    float algorithm_max_models_face;//人脸最大模板数
    //    float algorithm_vis_update;//k可见光模板更新阔值
    
    //    BOOL commitEndDataSuccess;//记录认证结果上传成功
    //    BOOL uniteFeatureSuccess;//记录模板合并接口上传成功
    
    
}

@property(nonatomic,strong) UIColor *navColor;//顶部导航栏背景颜色值
@property(nonatomic,assign) int showbackbtn;//顶部返回按钮 1显示，0不显示
@property(nonatomic,assign)int timeOUT;
@property (nonatomic,retain) id<getAliveDelegate> delegate;
@property(assign,nonatomic)NSInteger buttonIndex;
@property(nonatomic)int circleNumber;
@property(nonatomic,retain) NSString *timesTap;
@property(nonatomic,retain)NSMutableDictionary *endDic;
@property(nonatomic)BOOL fromRegister;// 判断是否是第一次注册
@property(nonatomic,retain)NSString*mycardid;
@property(nonatomic,retain)NSString *mypath0;
@property(nonatomic,assign)int number;

@end
