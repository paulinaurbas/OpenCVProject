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
	image.SetMatInput(imread(input, CV_LOAD_IMAGE_COLOR));
	if (!image.GetMatInput().data)
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	
	alpha_slider = 0;
	ShowPicture(image, "Color", 1);
	BlackAndWhite(image);
	imwrite("outputBW.jpg", image.GetMatOutput());
	ShowPicture(image, "BlackAndWhite", 0);
	Sepia(image);
	imwrite("outputSepia.jpg", image.GetMatOutput());
	ShowPicture(image, "Sepia", 0);
	image.SetMatOutput(EdgeDetection(image));
	imwrite("EdgeBW.jpg", image.GetMatOutput());
	ShowPicture(image, "Edge Detection", 0);
	Smooth(image);
	ShowPicture(image, "Smooth", 0);
	imwrite("smooth.jpg", image.GetMatOutput());
	Britness(image, 50);
	ShowPicture(image, "Brightness", 0);
	imwrite("brithness.jpg", image.GetMatOutput());
	waitKey(0);
	return 0;
	
}
