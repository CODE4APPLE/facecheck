//
//  FirstApprovedViewController.h
//  FaceCheck
//
//  Created by apple on 14-8-4.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "UIHelper.h"
//#import ""
//#import "UIImage+fixOrientation.h"
//#import "UIImage+Scale.h"
#import <AVFoundation/AVFoundation.h>
#import"BasicViewController.h"
#import "ApprovedViewController.h"

@protocol getMyAliveDelegate <NSObject>
-(NSString*)getAliveState:(NSString*)myalive;//得到活体结果
-(NSString*)getImage:(NSString*)myimage;
@end

@interface FirstApprovedViewController : BasicViewController<AVCaptureVideoDataOutputSampleBufferDelegate,getAliveDelegate>
{
    AVCaptureSession *_session;
    AVCaptureDeviceInput *_captureInput;
    AVCaptureStillImageOutput *_captureOutput;
    AVCaptureVideoPreviewLayer *_preview;
    AVCaptureVideoDataOutput *captureOutput;
    AVCaptureDevice *_device;
    dispatch_queue_t queue;
    
    BOOL isFront; // 记录摄像头的前后
    NSInteger answer_;

    int timeIndex;
    int countNum;
//    int  timeout;
    BOOL canCheck;
    BOOL alertShow;
    
    BOOL getFeatures;//get features

    
    
}
@property(nonatomic,assign) int timeout;
@property(nonatomic)BOOL fromRegister;
@property (nonatomic,retain) id<getMyAliveDelegate> delegate;

-(void)initRegory:(NSString *)path;//初始化算法


@end
