#pragma once
#ifndef BLINKDETECTOR_H
#define BLINKDETECTOR_H
//#include "opencv2/opencv.hpp"
// 定义函数调用方式
#define STD_CALL __stdcall

//#pragma comment(lib,"opencv_imgproc243.lib")
//#pragma comment(lib,"opencv_core243.lib")
//#pragma comment(lib,"opencv_highgui243.lib")

// 定义函数输出输入方式

#include "BasicFunction.h"
#include "AEyeBaseFaceStruct.h" 
#include "AEyePoseDetector.h"
// 定义函数返回结果
#define  AEYE_SUCCESS 0
#define  AEYE_FAIL    -1
#define  IN


/*******************************************************************

函 数 名 : InitBlinkModel

函数功能 : 初始化眨眼检测模型，载入局部运动模型和闭眼检测模型的数据文件 

函数参数 : [IN] : 
				  poseModelPath         pose检测模型文件
				  landmarkModelPath     关键点检测模型文件
函数返回 : 成功返回HANDLE, 失败NULL
********************************************************************/
HANDLE InitBlinkModel(IN char* poseModelPath, IN char* landmarkPath);
/*******************************************************************

函 数 名 : DetectLocalMove

函数功能 : 检测眼睛区域相邻两帧图像的局部运动，得到局部运动的置信度和决策判定

函数参数 : [IN] : hObject              dll对象的指针
                  pGrayBuf             当前帧灰度正立buffer
				  pGrayPreBuf          前一帧灰度正立buffer
                  width                图像宽
				  height               图像高
				  LeftEyeRect          当前帧左眼的矩形框
				  RightEyeRect         当前帧右眼的矩形框

           [OUT] : relia               局部运动检测的置信度，置信度越大，局部运动的可能性也越大
		   		   bLocalMove          局部运动判定输出：true为检测到局部运动，false为没有检测到

函数返回 : 成功返回AEYE_SUCCESS, 失败返回AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectLocalMove(IN HANDLE hObject, OUT bool& bLocalMove, IN BYTE* pGrayBuf, IN BYTE* pGrayPreBuf, IN int width, IN int height, IN s_Rect LeftEyeRect, IN s_Rect RightEyeRect, OUT double& relia);
/*******************************************************************

函 数 名 : DetectEyeStatus

函数功能 : 检测单帧图像中眼睛的睁、闭状态，得到闭眼的置信度和睁、闭眼状态的决策

函数参数 : [IN] : hObject              dll对象的指针
                  pGrayBuf             当前帧灰度正立buffer
                  width                图像宽
				  height               图像高
				  LeftEyeRect          当前帧左眼的矩形框
				  RightEyeRect         当前帧右眼的矩形框

           [OUT] : relia               睁、闭眼状态置信度， relia越大越可能是睁眼，relia越小越可能是闭眼
		   		   bEyeStatus          眼睛睁、闭状态决策输出：true为闭眼，false为睁眼

函数返回 : 成功返回AEYE_SUCCESS, 失败返回AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectEyeStatus(IN HANDLE hObject, OUT bool& bEyeStatus, IN BYTE* pGrayBuf, IN int width, IN int height, IN s_Rect LeftEyeRect, IN s_Rect RightEyeRect, OUT double& relia);
/*******************************************************************

函 数 名 : DetectImgStatus

函数功能 : 检测单帧图像状态的决策

函数参数 : [IN] : hObject              dll对象的指针
                  pNormImg             人脸归一化灰度图像正立buffer
				  width                图像宽
				  height               图像高

	       [OUT] : bImgStatus           活体图像状态，1为活体图像，0为非活体图像
				  score                图像状态得分

函数返回 : 成功返回AEYE_SUCCESS, 失败返回AEYE_FAIL

********************************************************************/
/*******************************************************************

函 数 名 : DetectLocalMove

函数功能 : 检测眼睛区域相邻两帧图像的局部运动，得到局部运动的置信度和决策判定

函数参数 : [IN] : hObject              dll对象的指针
				  currentFrameNum      当前帧序列号 
                  pGrayBuf             当前帧灰度正立buffer
				  pGrayPreBuf          前一帧灰度正立buffer
                  width                图像宽
				  height               图像高
				  eyeDet               人眼定位结构体
				  faceDet              人脸信息结构体
				  pNormImg             当前帧归一化图像
				  widthNor             归一化图像宽
				  heightNor            归一化图像高
				  bIfFirst             是否第一次调用此函数，true代表为第一次，false代表不是第一次

           [OUT] : qulityMSG            图像质量评估    0 为正常，1 为距离镜头太近， 2为距离镜头太远， 3，为局部光照太强， 4 为局部光照太暗，
		          bBlinkStatus         眨眼状态， 0为睁眼，1为闭眼
		          bAliveStatus         活体检测结果，0为活体，1为非活体，2为初始判定不确定，需要用户再试一次，-1为判断活体状态仍在进行中,-2 为活体检测超时判断
				  aliveDetectLevel    活体检测难易等级，1-4级，级别越高，难度越大，默认级别为3
				 


函数返回 : 成功返回AEYE_SUCCESS, 失败返回AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectImgStatus(IN HANDLE hObject, OUT bool& bImgStatus, IN BYTE* pNormImg,IN int width, IN int height,  OUT float& score);
long DetectAliveStatus(IN bool bIfFirst, OUT int *qulityMSG, OUT int *bAliveStatus, OUT double* unknown,
	IN BYTE* pGrayBuf, IN int width, IN int height, IN s_AEFace faceDet, IN int aliveDetectLevel);

#endif