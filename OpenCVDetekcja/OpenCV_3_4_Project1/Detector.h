#pragma once
#include "opencv2/opencv.hpp"

class Detector
{
protected:
	cv::Scalar uperColor;
	cv::Scalar lowerColor;

public:
	Detector();
	~Detector();

	bool detect(cv::Mat frame);
};



