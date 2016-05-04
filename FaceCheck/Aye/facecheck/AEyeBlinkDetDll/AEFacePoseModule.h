#ifndef __AEFACEPOSEMODULE_H__
#define __AEFACEPOSEMODULE_H__

#include <string>

namespace FaceRec {

	typedef struct MyRect
	{
		int x;
		int y;
		int height;
		int width;
	}MyRect;

class AEDLLExport AEFacePoseModule {
public:
	virtual void Unserialize( const std::string& Model )=0;
	virtual void PredictFacePose( unsigned char* image, int rows, int cols, MyRect& face_roi, float* Facepose )=0;
	virtual ~AEFacePoseModule(){};
};

}

#endif //__AEFACELANDMARKMODULE_H__
