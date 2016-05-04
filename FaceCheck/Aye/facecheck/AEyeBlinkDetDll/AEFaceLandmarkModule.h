#ifndef __AEFACELANDMARKMODULE_H__
#define __AEFACELANDMARKMODULE_H__

#include <string>
#include <opencv/cv.h>

namespace FaceRec {

class AEFaceLandmarkModule {
public:
	virtual void Unserialize( const std::string& Model )=0;
	virtual void PredictLandmark( const cv::Mat& image, const cv::Rect& face_roi, cv::Mat& landmark )=0;
    virtual ~AEFaceLandmarkModule(){};
};

}



#endif //__AEFACELANDMARKMODULE_H__
