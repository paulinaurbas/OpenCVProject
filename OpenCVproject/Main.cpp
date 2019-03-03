#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "User.h"
#include "ImageProcess.h"
//#include "TrackBar.h"
using namespace cv;
using std::cout;

using namespace cv;
using namespace std;
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src;
Mat src2;
Mat dst;
/*static void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider / alpha_slider_max;
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	imshow("Linear Blend", dst);
}*/

int main(int argc, char *argv[])
{
	string input = "Melon.jpg";
	string output = "output.jpg";
	Image image;
	image.input = imread(input, CV_LOAD_IMAGE_COLOR);
	if (!image.input.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	alpha_slider = 0;
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
	waitKey(0);
	return 0;
}
