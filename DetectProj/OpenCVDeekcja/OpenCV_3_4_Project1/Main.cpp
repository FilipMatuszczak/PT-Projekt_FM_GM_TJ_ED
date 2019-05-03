#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "BlueDetector.h"
#include "RedDetector.h"
#include "GreenDetector.h"

using namespace cv;
using namespace std;

Mat detectBlueObject(Mat frame) {
	//cvtColor(frame, frame, COLOR_BGR2HSV);

	inRange(frame, Scalar(100, 0, 0), Scalar(255, 100, 100), frame);
	//GaussianBlur(result, result, Size(7, 7), 1.5, 1.5);
	medianBlur(frame, frame, 5);
	//Canny(edges, edges, 0, 30, 3);

	return frame;
}

int main(int, char**)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;


	vector<Detector*> detectVector;
	detectVector.push_back(new BlueDetector());
	
	detectVector.push_back(new GreenDetector());
	detectVector.push_back(new RedDetector());

	namedWindow("result", 1);
	namedWindow("normalView", 2);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera

		//circle(frame, Point(200, 200), 100, Scalar(0, 28, 255));

		for (int i = 0; i < detectVector.size(); i++)
		{
			if (detectVector[i]->detect(frame))
				break;
		}
		imshow("normalView", frame);
		
		
		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}