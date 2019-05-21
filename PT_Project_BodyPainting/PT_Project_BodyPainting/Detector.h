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
	cv::Scalar upperColor;
	cv::Scalar lowerColor;
	cv::Scalar lowerBoundary = cv::Scalar(125, 75, 40);
	cv::Scalar upperBoundary = cv::Scalar(150, 255, 255);
public:
	Detector();
	~Detector();

	int getX();
	int getY();
	cv::Point2d getResolution();
	bool detect();

	bool isCameraOK();
	
};



