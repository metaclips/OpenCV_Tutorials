// OpenCV Tutorials.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <opencv2/ml.hpp>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
	Mat image = imread(argv[1], -1);
	if (image.empty())
	{
		cout << "No image input" << endl;
		cout << "exiting" << endl;
		exit(0);
	}
	cvNamedWindow("output", CV_WINDOW_FULLSCREEN);
	imshow("output", image);
	cvWaitKey(0);
    return 0;
}

