#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "ImageProcess.h"
#include "User.h"
void ShowPicture(const Image & input, const string Info, int number)
{
	namedWindow(Info, CV_WINDOW_AUTOSIZE);
	if (number == 0)
	{
		imshow(Info, input.output);
	}
	else
	{
		imshow(Info, input.input);
	}
}
