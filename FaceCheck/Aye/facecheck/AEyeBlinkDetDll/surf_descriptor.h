/**
 * @file descriptor.h
 * @brief Header for SURF SurfDescriptor
 * @author 
 * This part will direct how to build the SurfDescriptor.
 *
 */



#ifndef SURF_DESCRIPTOR_H

#define SURF_DESCRIPTOR_H
#include <opencv2/opencv.hpp>

class SurfDescriptor
{
public:
	SurfDescriptor();/*:desc_num(64)
					 {
					 }*/

    SurfDescriptor(cv::Mat &img, cv::Mat &landmark, cv::Mat &feat):desc_num(64)
    {
        calcDescriptors(img, landmark, feat);
    }
    void calcDescriptors(const cv::Mat &img,const  cv::Mat &landmark, cv::Mat &feat);
    int desc_num;
private:
	void calcPointDescriptors(const int *p_exp_imgx, const int *p_exp_imgy, const int &exp_width, const cv::Point &point, cv::Mat &feat);

//---
	cv::Mat gaussker;

};

#endif