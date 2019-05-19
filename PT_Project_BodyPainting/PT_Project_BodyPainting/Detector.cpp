#include "Detector.h"
#include <vector>

using namespace cv;
Detector::Detector()
{
	cameraOK = true;
	cap = VideoCapture(0);
	if (!cap.isOpened()) 
	{
		cameraOK = false;
		printf("Camera did not work");
	}
	else
	{
		namedWindow("result", 1);
	}
	
		
}

Detector::~Detector()
{
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
	//color detect//
	Mat frame;
	Mat src;
	cap >> src;
	//Mat hsv_purple;
	//Mat bgr_purple = Mat(1, 1, CV_8UC3, Scalar(270, 70, 70));
	inRange(src, lowerColor, uperColor, frame);

	medianBlur(frame, frame, 7);

	//cvtColor(frame, hsv_purple, COLOR_BGR2HSV);


	std::vector<Vec3f> circles;

	//circle detect//
	HoughCircles(frame, circles, CV_HOUGH_GRADIENT, 1, frame.rows / 8, 30, 15, 20, 70);


	printf("%d", circles.size());

	if(circles.size() > 0)
	{
		x = circles[0][0];
		y = circles[0][1];
		circle(src, Point(x, y), 100, Scalar(0, 28, 255));
	}
	
	imshow("normalView", src);

	return (circles.size() > 0);
}

bool Detector::isCameraOK()
{
	return cameraOK;
}
