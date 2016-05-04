#ifndef AE_FACE_LANDMARK_SDM_H
#define AE_FACE_LANDMARK_SDM_H

#include <opencv2/core/core.hpp>
#include "AECommon.h"
#include "AEFaceLandmarkModule.h"

namespace FaceRec {

class  AEDLLExport AEFaceLandmarkSdmModule: public AEFaceLandmarkModule
{
public:
    AEFaceLandmarkSdmModule();
    virtual ~AEFaceLandmarkSdmModule();
	virtual void Unserialize(const std::string &model);

	//!@param landmark is a colomn,like [x, y, x , y ...]'
	virtual void PredictLandmark(const cv::Mat &image, const cv::Rect &face_roi, cv::Mat &landmark);

private:
    void * CommonPtr;
};

AEDLLExport AEFaceLandmarkModule* CreateAEFaceLandmarkSdmModuleModule();

}
#endif