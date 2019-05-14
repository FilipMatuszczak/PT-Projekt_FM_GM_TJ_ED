#include "RedDetector.h"

using namespace cv;

RedDetector::RedDetector()
{
	this->uperColor = cv::Scalar(100, 100, 255);
	this->lowerColor = cv::Scalar(0, 0, 100);
}


RedDetector::~RedDetector()
{
}
