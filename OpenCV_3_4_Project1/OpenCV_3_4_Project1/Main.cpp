#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace cv;
using namespace std;


/*int main(int argc, char** argv)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;
	int blueLower[] = { 100,60,60 };
	int blueUpper[] = { 140,255,255 };
	Mat edges;
	Mat BlueMask;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, COLOR_BGR2HSV);
		imshow("Camera", edges);
		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}*/

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;

const String window_capture_name = "Video Capture";
const String window_detection_name = "Object Detection";

const Scalar lowerBoundary = Scalar(100, 60, 60);
const Scalar upperBoundary = Scalar(140, 255, 255);

int main(int argc, char* argv[])
{
	VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);
	namedWindow(window_capture_name);
	namedWindow(window_detection_name);
	Mat frame, frame_HSV, frame_threshold;
	while (true) {
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		// Convert from BGR to HSV colorspace
		cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
		// Detect the object based on HSV Range Values
		inRange(frame_HSV, lowerBoundary, upperBoundary, frame_threshold);
		// Show the frames
		imshow(window_capture_name, frame);
		imshow(window_detection_name, frame_threshold);
		char key = (char)waitKey(30);
		if (key == 'q' || key == 27)
		{
			break;
		}
	}
	return 0;
}