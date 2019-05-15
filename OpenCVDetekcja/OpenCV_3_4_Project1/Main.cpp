//#include "Detector.h"
//#include "BlueDetector.h"
//#include "RedDetector.h"
//#include "GreenDetector.h"
//#include "PurpleDetector.h"
//
//using namespace cv;
//using namespace std;
//
//Mat detectBlueObject(Mat frame) {
//	//cvtColor(frame, frame, COLOR_BGR2HSV);
//
//	inRange(frame, Scalar(100, 0, 0), Scalar(255, 100, 100), frame);
//	//GaussianBlur(result, result, Size(7, 7), 1.5, 1.5);
//	medianBlur(frame, frame, 5);
//	//Canny(edges, edges, 0, 30, 3);
//
//	return frame;
//}
//
//int main(int, char**)
//{
//	VideoCapture cap(0); // open the default camera
//	if (!cap.isOpened())  // check if we succeeded
//		return -1;
//
//
//	vector<Detector*> detectVector;
//	//detectVector.push_back(new PurpleDetector());
//	//detectVector.push_back(new BlueDetector());
//	detectVector.push_back(new GreenDetector());
//	//detectVector.push_back(new RedDetector());
//	
//
//	namedWindow("result", 1);
//	namedWindow("normalView", 2);
//	for (;;)
//	{
//		Mat frame;
//		cap >> frame; // get a new frame from camera
//
//		//circle(frame, Point(200, 200), 100, Scalar(0, 28, 255));
//
//		for (int i = 0; i < detectVector.size(); i++)
//		{
//			if (detectVector[i]->detect(frame))
//				break;
//		}
//		imshow("normalView", frame);
//		
//		
//		if (waitKey(30) >= 0) break;
//	}
//	// the camera will be deinitialized automatically in VideoCapture destructor
//	return 0;
//}

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace cv;

bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2);


const String window_capture_name = "Video Capture";
const String window_detection_name = "Object Detection";

const Scalar lowerBoundary = Scalar(130, 75, 40);
const Scalar upperBoundary = Scalar(155, 255, 255);




int main(int argc, char* argv[])
{
	std::vector<std::vector<int>> kernel(5, std::vector<int>(1, 5));
	VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
	namedWindow(window_capture_name);
	//namedWindow(window_detection_name);
	Mat frame, frame_HSV, frame_threshold, temp;
	while (true) {
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
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
			Moments moment = moments(contours[contours.size() - 1], false);


			//THAT IS THE CENTRE POINT. THIS NEEDS TO BE THROWN TO MATES IN UI
			Point2f mass_centre(moment.m10 / moment.m00, moment.m01 / moment.m00);


			drawContours(frame, contours, contours.size() - 1, { 255,255,255 }, 2, 8, hierarchy, 0, Point());
			circle(frame, mass_centre, 4, { 255,255,255 }, -1, 8, 0);
		}



		// Show the frames
		imshow(window_capture_name, frame);
		//imshow(window_detection_name, frame_threshold);
		char key = (char)waitKey(30);
		if (key == 'q' || key == 27)
		{
			break;
		}
	}
	return 0;
}

bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2)
{
	double i = fabs(contourArea(cv::Mat(contour1)));
	double j = fabs(contourArea(cv::Mat(contour2)));
	return (i < j);
}