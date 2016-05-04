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
	// ��ʼ��poseDetectģ�ͣ�model_pathΪģ��·��
	bool LoadModule(const char* model_path);
	//����Ƿ���
	bool LandmarkDetect(IplImage* image, s_AEFace& face_info, cv::Mat& landmark);
private:
	FaceRec::AEFaceLandmarkModule* m_sdm_detector;
};
#endif