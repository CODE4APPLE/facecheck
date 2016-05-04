#ifndef __AECONVNN_H__
#define __AECONVNN_H__


#include "AECommon.h"
//#include <opencv2/opencv.hpp>
#include <vector>
#include <string>


namespace ConvNN {

typedef float NN_TYPE;
class NNSignalElement {
public:
	typedef struct _SignalDim {
		INT width_;
		INT height_;
		INT channels_;
		INT GetSignalSize()const;
		//void UnSerialize( const cv::FileNode& node );

		void UnSerialize( FILE* fp );
	}SignalDim;

	SignalDim dim_;
	std::vector<NN_TYPE> sig_;
	NNSignalElement();
	explicit NNSignalElement( const SignalDim& dim );
	SignalDim GetSignalDim()const;
	NN_TYPE* GetData();
	const NN_TYPE* GetData()const;
	void Resize( const SignalDim& in_dim );
};


class AEConvNN {
public:
	AEConvNN():conv_core_(NULL){};
	void FeedForward( const NNSignalElement& src_data, NNSignalElement& out_data ) const;
	void load( const std::string& para_file );


	~AEConvNN();
private:
	void *conv_core_;
private:
	DISALLOW_COPY_AND_ASSIGN(AEConvNN);
};


};

#endif
