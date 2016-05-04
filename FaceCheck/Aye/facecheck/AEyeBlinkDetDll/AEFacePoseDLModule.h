#ifndef AEFACEPOSEDLMODULE_H_
#define AEFACEPOSEDLMODULE_H_


#include "AECommon.h"
#include "AEFacePoseModule.h"
#include "AEConvNN.h"
#include <cmath>
#include <algorithm>

#define FrontYawmin     -0.17444
#define FrontYawmax      0.17444
#define FrontPitchmin   -0.17444
#define FrontPitchmax   0.08722
#define LeftYawmin      -0.52333
#define LeftYawmax		-0.17444
#define RightYawmin      0.17444
#define RightYawmax		0.52333
#define UpPitchmin       0.08722
#define UpPitchmax		 0.52333
#define DownPitchmin     -0.52333
#define DownPitchmax	-0.17444


const float posevalue[] = {FrontYawmin,FrontYawmax,FrontPitchmin,FrontPitchmax,LeftYawmin,LeftYawmax,RightYawmin,RightYawmax,UpPitchmin,UpPitchmax,DownPitchmin,DownPitchmax };

namespace FaceRec{

class AEDLLExport AEFacePoseDLModule: public AEFacePoseModule {
public:
	AEFacePoseDLModule();
	virtual ~AEFacePoseDLModule();
	virtual void Unserialize( const std::string& Model );
	virtual void PredictFacePose(unsigned char* gray_image, int rows, int cols, MyRect& face_roi, float* facepose);
	virtual int PredictFaceDirect(unsigned char* gray_image, int rows, int cols, MyRect& face_roi, const float* PoseValue);


private:
	ConvNN::AEConvNN conv;
	void  TransImageToNNSignal( unsigned char* image, int rows, int cols, ConvNN::NNSignalElement& signal );
	float GetExtendRoiImage(unsigned char* gray_image, int rows, int cols, const MyRect& roi_rect, unsigned char* dst_image );
	virtual void ToEuler(float* quatern, float* angle);
};

AEDLLExport AEFacePoseModule* CreateAEFacePoseDLModule();

}

#endif /* AEFACEPOSEDLMODULE_H_ */
