#pragma once
#include "opencv2/opencv.hpp"


class Detector
{
private:
	int x;
	int y;
	bool cameraOK;
	cv::VideoCapture cap;

protected:
	cv::Scalar uperColor;
	cv::Scalar lowerColor;

public:
	Detector();
	~Detector();

	int getX();
	int getY();

	bool detect();

	bool isCameraOK();
};



