#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	VideoCapture video;
	video.open(argv[1]);
	Mat image;
	auto frame = video.get(CAP_PROP_FPS);
	cout << frame;
	cvNamedWindow("video output", WINDOW_FREERATIO);
	for (;;)
	{
		video >> image;
		if (image.empty())break;
		imshow("video output", image);
		auto key = waitKey(frame);
		cout << key;
		if (key == int('o'))
		{
			cvNamedWindow("output", WINDOW_FREERATIO);
			imshow("output", image);
		}
	}
	cout << "Movie Over" << endl;
	system("Pause");
	return 0;
}