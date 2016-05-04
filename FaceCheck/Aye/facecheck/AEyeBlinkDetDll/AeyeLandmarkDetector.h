#ifndef _AEYE_LANDMARK_DETECTOR_H_
#define _AEYE_LANDMARK_DETECTOR_H_

#include "AEyeBaseFaceStruct.h"
#include "AEFaceLandmarkSdmModule.h"
#include <opencv2/opencv.hpp>

class AEyeLandmarkDetector
{
public:
	AEyeLandmarkDetector();
	~AEyeLandmarkDetector();
	// 初始化poseDetect模型，model_path为模型路径
	bool LoadModule(const char* model_path);
	//检测是否有
	bool LandmarkDetect(IplImage* image, s_AEFace& face_info, cv::Mat& landmark);
private:
	FaceRec::AEFaceLandmarkModule* m_sdm_detector;
};
#endif