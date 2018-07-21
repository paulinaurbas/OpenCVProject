#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "User.h"
#include "ImageProcess.h"
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
	Image image;
	image.input = imread("tygrys.jpg", CV_LOAD_IMAGE_COLOR);
	if (!image.input.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	ShowPicture(image, "Color", 1);
	BlackAndWhite(image);
	ShowPicture(image, "BlackAndWhite", 0);
	Sepia(image);
	ShowPicture(image, "Sepia", 0);
	image.output = EdgeDetection(image);
	ShowPicture(image, "Edge Detection", 0);
	Smooth(image);
	ShowPicture(image, "Smooth", 0);
	Britness(image, 50);
	ShowPicture(image, "Brightness", 0);
	waitKey();
	return 0;
}