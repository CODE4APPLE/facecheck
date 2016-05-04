#ifndef _GET_THRES_H_
#define _GET_THRES_H_

#include <assert.h>
#include "BasicFunction.h"
#include <time.h>
//#include "opencv2/opencv.hpp"
//#define OUT
//using namespace cv;
using namespace std; 
#define IMG_WIDTH 112
#define IMG_HEIGHT 144
#define FACE_IMG_WIDTH 64
#define FACE_IMG_HEIGHT 64

#if defined(__cplusplus)
extern "C"
{
#endif

	//float AliveImgResult(IplImage* pGrayImg);
	double getTime(); //使用高精度计时器 
	//int calSub(Mat &m);
	int getDistribution(float ratioNum);
	
	
#if defined(__cplusplus)
}
#endif
#endif







