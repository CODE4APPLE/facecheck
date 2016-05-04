#pragma once

#include "AEyeBaseFaceStruct.h"
// 定义函数调用方式
#define STD_CALL __stdcall

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef EXPORT_FRONTAL_FACE_DETECT
#define FRONTAL_FACE_DETECT_0_DLL_API __declspec(dllexport)
#else
#define FRONTAL_FACE_DETECT_0_DLL_API __declspec(dllimport)
#endif

	// 定义函数返回结果
#define  AEYE_SUCCESS 0
#define  AEYE_FAIL    -1

	// 设置facedetection相关参数
	// pPara是需要设置的参数列表，第0个表示rectNum阈值，此版可见光的经验值rectNum为3
	//如果正面（序号0）模型没有初始化正确,则返回值result为1,
	//如果左侧[-45,-20]度（序号1）没有初始化正确,则返回值result为2,
	//如果右侧[20,45]度（序号2）没有初始化正确,则返回值result为3,
	//如果低头[-45,-20]度（序号3）没有初始化正确,则返回值result为4,
	//如果平面内旋转[-75,-46]（序号5）模型没有初始化正确,则返回值result为5,
	//如果平面内旋转[-45,-16]（序号6）模型没有初始化正确,则返回值result为6,
	//如果平面内旋转[16,45]（序号7）模型没有初始化正确,则返回值result为7,
	//如果平面内旋转[46,75]（序号8）模型没有初始化正确,则返回值result为8,
	//如果每个模型都返回正确,则返回值result为9
	FRONTAL_FACE_DETECT_0_DLL_API HANDLE STD_CALL CreateFaceDetector(int &result, int *pPara);
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL DestroyFaceDetector(HANDLE hObject);

	//PositionFace人脸检测处理函数
	/****************************************************************************/
	/* 函数功能：进行人脸检测，从内存中读取检测模型                             */
	/* 参数：                                                                   */ 
	/* 	   unsigned char * pImg：正立一维灰度图像buffer首指针                   */
	/* 	   int imgWidth：        图像宽度                                       */
	/* 	   int imgHeight：       图像高度                                       */
	/*     int minWidth：        检测人脸的最小尺度                             */
	/*     int maxWidth：        检测人脸的最大尺度                             */
	/*     s_AERect searchROI：  确定检测的人脸在图像中的搜索位置范围           */
	/*     返回值为0，则正确，返回值为其他值，则错误                            */
	/*	   PositionFace(pProcImg, srcImg.Width(), srcImg.Height(), (faceRect.bottom - faceRect.top)/2, (faceRect.bottom - faceRect.top)*2, searchROI);*/
	/*     int *pPara是需要设置的参数列表，第0个表示rectNum阈值，此版可见光的经验值rectNum为3*/
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL PositionFace(HANDLE hObject, unsigned char * pImg, int imgWidth, int imgHeight,int minWidth, int maxWidth, s_AERect searchROI, int *pPara);

	//PositionFace多姿态人脸检测处理函数
	/****************************************************************************/
	/* 函数功能：进行多姿态人脸检测，会直接从内存中读取检测模型，无需外界调用初始化函数*/
	/* 参数：                                                                   */ 
	/* 	   unsigned char * pImg：正立一维灰度图像buffer首指针                   */
	/* 	   int imgWidth：        图像宽度                                       */
	/* 	   int imgHeight：       图像高度                                       */
	/*     int minWidth：        检测人脸的最小尺度                             */
	/*     int maxWidth：        检测人脸的最大尺度                             */
	/*     s_AERect searchROI：  确定检测的人脸在图像中的搜索位置范围           */
	/*     int *pViewControl    多姿态人脸检测参数                              */
	/*     多姿态人脸检测，现在共支持正面（序号0），左侧[-45,-20]度（序号1），右侧[20,45]度（序号2），
	/*     低头[-45,-20]度（序号3），仰头[20,45]度（序号4），平面内旋转[-75,-46]（序号5），
	/*     平面内旋转[-45,-16]（序号6），平面内旋转[16,45]（序号7），平面内旋转[46,75]（序号8）共九个姿态
	/*     int *pViewControl为指针，其长度等于支持的姿态数目，现在为9，顺序按照上述括号中给出的序号，
	/*     其每个值，如果为1，表示进行该序号对应姿态的检测，否则不进行检测
	/*     如果pViewControl为NULL，则进行所有姿态的人脸检测
	/*     返回值为0，则正确，返回值为其他值，则错误                            */
	/* PositionMultiViewFace(pProcImg, srcImg.Width(), srcImg.Height(), (faceRect.bottom - faceRect.top)/2, (faceRect.bottom - faceRect.top)*2, searchROI, NULL);*/
	/*     int *pPara是需要设置的参数列表，第0个表示rectNum阈值，此版可见光的经验值rectNum为3*/
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL PositionMultiViewFace(HANDLE hObject,unsigned char * pImg, int imgWidth, int imgHeight,int minWidth, int maxWidth, s_AERect searchROI, int *pViewControl, int *pPara);

	/****************************************************************************/
	/* 函数功能：进行人脸检测后获得检测到人脸的数目                             */
	/* 参数：                                                                   */ 
	/* 	   直接得到函数输出的人脸数目                                           */
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL GetFaceNum(int &faceNum, HANDLE hObject);

	/****************************************************************************/
	/* 函数功能：根据输入的人脸数目得到人脸的具体位置                           */
	/* 参数：                                                                   */ 
	/*           	s_Rect faceDetRect;                                         */
	/* 	            faceNum = GetFaceNum();                                     */
	/* 	 	for (i = 0; i < faceNum; i ++)                                    */
	/*		{                                                                   */
	/*                  faceDetRect = GetFaceRect(i);                           */
	/*      }                                                                   */ 
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL GetFaceRect(s_AEFace &faceDetRect, HANDLE hObject,int faceOrder);

#if defined(__cplusplus)
}
#endif
