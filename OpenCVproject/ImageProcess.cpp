#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "ImageProcess.h"
using namespace cv;
void BlackAndWhite( Image & image)
{
	try
	{
		cvtColor(image.input, image.output, CV_BGR2GRAY);
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}
Mat MakeKernel ()
{
	try
	{
		Mat kernel = (cv::Mat_<float>(3, 3)
			<<
			0.272, 0.534, 0.131,
			0.349, 0.686, 0.168,
			0.393, 0.769, 0.189);
		return kernel;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}
void Sepia(Image & image)
{
	try
	{
		Mat Kernel = MakeKernel();
		cv::transform(image.input, image.output, Kernel);
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}
Mat EdgeDetection(Image & image)
{
	Mat gray, dst, dst_abs;
	GaussianBlur(image.input, image.input, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(image.input, gray, CV_RGB2GRAY);
	Laplacian(gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, dst_abs);
	return dst_abs;
}
void Smooth(Image & image)
{
	GaussianBlur(image.input, image.output, Size(5, 5), 3, 3);
	GaussianBlur(image.output, image.output, Size(5, 5), 3, 3);
}
void Britness(Image & image, int number)
{
	image.input.convertTo(image.output, -1, 1, number);
}
void Contrast(Image & image)
{
	int alfa, beta;
	image.output = Mat::zeros(image.input.size(), image.input.type());
	std::cout << "*Enter the alpha value [1.0-3.0]:"; std::cin >> alfa;
	std::cout << "*Enter the beta value [0-100]:"; std::cin >> beta;
	for (int y = 0; y < image.input.rows; y++)
	{
		for (int x = 0; x < image.input.cols; x++)
		{
			for (int c =0; c< 3; c++)
			{
				image.output.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alfa*(image.input.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}
}