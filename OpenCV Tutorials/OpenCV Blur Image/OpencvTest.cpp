#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

VideoCapture video;

int main(int argc, char** argv)
{
	Mat image,bimage,eimage;
	image = imread(argv[1],-1);
	//GaussianBlur(image, bimage, Size(0, 0),3,3);
	//GaussianBlur(bimage, bimage, Size(0, 0), 3, 3);
	
	for (;;)
	{
		imshow("Output Image", image);
		char val = waitKey(27);
		if (val == 'i')
		{
			pyrUp(image, image, Size(image.cols * 2, image.rows * 2));
		}
		else if (val == 'd')
			pyrDown(image, image, Size(image.cols / 2, image.rows / 2));
	}
	imshow("Output Image", image);
	namedWindow("Blurr Output Image", CV_WINDOW_FREERATIO);
	namedWindow("edge Image", CV_WINDOW_FREERATIO);
	cvtColor(image, bimage,COLOR_BGR2RGBA);
	imshow("Blurr Output Image", bimage);
	imwrite("../image.jpg", bimage);
	Canny(bimage, eimage, 10, 100, 3, true);
	imshow("edge Image", eimage);
	waitKey(0);
	system("Pause");
	return 0;
}