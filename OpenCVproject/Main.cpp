#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "User.h"
#include "ImageProcess.h"
using namespace cv;
int main(int argc, char *argv[])
{
	try
	{
		string input;
		string output;
		int nb = 0; 
		//int number = CheckTerminal(argc, argv, input, nb, output);
		//if (number == 0)
			Image image;
			image.input = imread("melon.jpg", CV_LOAD_IMAGE_COLOR);
			if (!image.input.data)
			{
				cout << "Could not open or find the image" << std::endl;
				return 0;
			}
			std::cout << "paula" << std::endl;
			ShowPicture(image, "Color", 1);
			BlackAndWhite(image);
			imwrite("outputBW.jpg", image.output);
			ShowPicture(image, "BlackAndWhite", 0);
			Sepia(image);
			imwrite("outputSepia.jpg", image.output);
			ShowPicture(image, "Sepia", 0);
			image.output = EdgeDetection(image);
			imwrite("EdgeBW.jpg", image.output);
			ShowPicture(image, "Edge Detection", 0);
			Smooth(image);
			ShowPicture(image, "Smooth", 0);
			imwrite("smooth.jpg", image.output);
			Britness(image, 50);
			ShowPicture(image, "Brightness", 0);
			imwrite("brithness.jpg", image.output);
			//waitKey();
			return 0;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}