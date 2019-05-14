#include "GreenDetector.h"

using namespace cv;

GreenDetector::GreenDetector()
{
	this->uperColor = cv::Scalar(130, 255, 90);
	this->lowerColor = cv::Scalar(0, 100, 0);
}


GreenDetector::~GreenDetector()
{
}
