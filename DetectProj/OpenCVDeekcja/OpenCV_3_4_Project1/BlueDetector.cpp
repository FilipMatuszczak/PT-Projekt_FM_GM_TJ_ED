#include "BlueDetector.h"

using namespace cv;

BlueDetector::BlueDetector()
{
	this->uperColor = cv::Scalar(255, 100, 100);
	this->lowerColor = cv::Scalar(100, 0, 0);
}


BlueDetector::~BlueDetector()
{
}
