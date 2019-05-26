#include "Detector.h"
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2);

Detector::Detector()
{
	cameraOK = true;
	cap = VideoCapture(0);
	if (!cap.isOpened()) 
	{
		cameraOK = false;
		printf("Camera did not work");
	}
	
	
		
}

Detector::~Detector()
{
}

Point2d Detector::getResolution()
{
	return { cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT) };
}

int Detector::getX()
{
	return x;
}

int Detector::getY()
{
	return y;
}

bool Detector::detect()
{
	
	Mat frame, frame_HSV, frame_threshold, temp;
	
	cap >> frame;
		
	flip(frame, frame, +1);
	// Convert from BGR to HSV colorspace
	cvtColor(frame, frame_HSV, COLOR_BGR2HSV);

	// Detect the object based on HSV Range Values
	inRange(frame_HSV, lowerBoundary, upperBoundary, frame_threshold);


	std::vector<std::vector<Point>> contours = {};
	std::vector<Vec4i> hierarchy = {};
	findContours(frame_threshold, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	if (contours.size() > 0)
	{
		std::sort(contours.begin(), contours.end(), compareContourAreas);
		if (fabs(contourArea(cv::Mat(contours[contours.size() - 1]))) > 50.0) {
			Moments moment = moments(contours[contours.size() - 1], false);


			//THAT IS THE CENTRE POINT. THIS NEEDS TO BE THROWN TO MATES IN UI
			Point2f mass_centre(moment.m10 / moment.m00, moment.m01 / moment.m00);
			x = mass_centre.x;
			y = mass_centre.y;


			drawContours(frame, contours, contours.size() - 1, { 255,255,255 }, 2, 8, hierarchy, 0, Point());
			circle(frame, mass_centre, 4, { 255,255,255 }, -1, 8, 0);
		}
	}
	
	return (contours.size() > 0);
}

bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2)
{
	double i = fabs(contourArea(cv::Mat(contour1)));
	double j = fabs(contourArea(cv::Mat(contour2)));
	return (i < j);
}

bool Detector::isCameraOK()
{
	return cameraOK;
}