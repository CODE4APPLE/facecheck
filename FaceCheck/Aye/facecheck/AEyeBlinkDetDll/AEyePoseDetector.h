#ifndef _AEYE_POSE_DETECTOR_H_
#define _AEYE_POSE_DETECTOR_H_

#include "AEyeBaseFaceStruct.h"
#include "AEFacePoseDLModule.h"

using namespace ConvNN;
using namespace FaceRec;

typedef struct POSE_3D
{
	float yaw;
	float pitch;
	float roll; 
}POSE_3D;

#define FACE_FRONT 0
#define FACE_LEFT  1
#define FACE_RIGHT 2
#define HEAD_UP    3
#define HEAD_DOWN  4
class AEyePoseDetector
{
public:
	AEyePoseDetector();
	// 初始化poseDetect模型，model_path为模型路径
	bool LoadModule(char* model_path);
	// 姿态检测，输入图像和人脸信息，输出3D坐标信息，返回值为对应姿态
	int PoseDetect(unsigned char* image, int rows, int cols, s_AEFace& face_info, POSE_3D& pose_info);
	// 
	int PoseDetect(float yaw, float pitch, float roll);
private:
	AEFacePoseDLModule m_face_module; 
};

#endif