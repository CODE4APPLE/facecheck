#ifndef SDM_COMMON_H
#define SDM_COMMON_H


#include <opencv2/core/core.hpp>

namespace FaceRec
{
	class SdmCommon
	{
	public:
		SdmCommon();
		~SdmCommon();

		bool load(const std::string &model_name);
		bool save(const std::string &model_name);

		void NormImage(const cv::Mat &image, const cv::Rect &face_roi, cv::Mat &norm_img,
			cv::Rect &dst_box, cv::Rect &back_rect, float &back_ratio);
		void InitLandmark(const cv::Rect &src_box, cv::Mat &landmark);
		void ExtractFeature(const cv::Mat &image, const cv::Mat &landmark, cv::Mat &feat);

		// parameters
		int _norm_box_size;
		float _extension_ratio; // one side


		// model part
		int _point_num;
		int _iteration;
		cv::Mat _mean_shape;
		std::vector<cv::Mat> _R;
		std::vector<cv::Mat> _b;


	};
}


#endif