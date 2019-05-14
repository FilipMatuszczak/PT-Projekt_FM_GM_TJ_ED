#include "PurpleDetector.h"

using namespace cv;

PurpleDetector::PurpleDetector()
{
	this->uperColor = cv::Scalar(230, 90, 190);
	this->lowerColor = cv::Scalar(120, 0, 70);
}


PurpleDetector::~PurpleDetector()
{
}
