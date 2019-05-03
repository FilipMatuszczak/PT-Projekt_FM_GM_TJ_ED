#include "GreenDetector.h"

using namespace cv;

GreenDetector::GreenDetector()
{
	this->uperColor = cv::Scalar(100, 255, 100);
	this->lowerColor = cv::Scalar(0, 100, 0);
}


GreenDetector::~GreenDetector()
{
}
