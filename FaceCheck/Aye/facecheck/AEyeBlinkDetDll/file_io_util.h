#ifndef FILE_IO_UTIL_H
#define FILE_IO_UTIL_H

#include <string>

#include <opencv2/opencv.hpp>



template <typename T>
bool write_n(FILE * file, const T * data, size_t n);

template <typename T>
bool read_n(FILE * file, T * data, size_t n);

//template <typename T>
//bool write_one(FILE * file, T data);
//
//template <typename T>
//bool read_one(FILE * file, T & data);


template <typename T>
bool write_one(FILE * file, T data)
{
	return write_n(file, &data, 1);
}

template <typename T>
bool read_one(FILE * file, T & data)
{
	return read_n(file, &data, 1);
}

// Write one cv::Mat to file
bool write_one(FILE * file, const cv::Mat & data);

// Read one cv::Mat from file
bool read_one(FILE * file, cv::Mat & data);

bool write_mat(std::string &data_name, const cv::Mat & data);

bool read_mat(std::string &data_name, cv::Mat & data);

#endif