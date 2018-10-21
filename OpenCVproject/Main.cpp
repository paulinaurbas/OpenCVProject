#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "User.h"
#include "ImageProcess.h"
#include "TrackBar.h"
using namespace cv;
using std::cout;

using namespace cv;
using namespace std;
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src1;
Mat src2;
Mat dst;


int main(int argc, char *argv[])
{
	src1 = imread("../Examples/foto.jpg");
	src2 = imread("../Examples/foto.jpg");

	if (src1.empty()) { cout << "Error loading src1 \n"; return -1; }
	if (src2.empty()) { cout << "Error loading src2 \n"; return -1; }

	alpha_slider = 0;

	namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window

	char TrackbarName[50];
	sprintf(TrackbarName, "Alpha x %d", alpha_slider_max);
	createTrackbar(TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);

	on_trackbar(alpha_slider, 0);

	waitKey(0);
	return 0;
}
	/*try
	{
		string input;
		string output;
		int nb = 0; 
		int number = CheckTerminal(argc, argv, input, nb, output);
		if (number == 0)
		{
			Image image;
			image.input = imread(input, CV_LOAD_IMAGE_COLOR);
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
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}*/