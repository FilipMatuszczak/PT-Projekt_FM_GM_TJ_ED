#include "Detector.h"
#include <vector>

using namespace cv;
Detector::Detector()
{
}

Detector::~Detector()
{
}

bool Detector::detect(cv::Mat src)
{
	//color detect//
	Mat frame;
	inRange(src,  lowerColor, uperColor, frame);

	medianBlur(frame, frame, 7);

	std::vector<Vec3f> circles;

	//circle detect//
	HoughCircles(frame, circles, CV_HOUGH_GRADIENT, 1, frame.rows / 8, 30, 15, 20, 70);

	printf("%d", circles.size());
	
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle(src, center, 3, uperColor, -1, 8, 0);
		// circle outline
		circle(src, center, radius, uperColor, 3, 8, 0);
	}
	//imshow("result", frame);
	//imshow("normalView", src);
	

	return (circles.size() > 0);
}
