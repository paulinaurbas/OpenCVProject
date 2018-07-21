#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;
class Image
{
public:
	Mat input;
	Mat output;
};
Mat MakeKernel();
void BlackAndWhite(Image & image);
void Sepia (Image & image);
Mat EdgeDetection (Image & image);
void Smooth(Image & image);
void Britness(Image & image, int number);
void Contrast(Image & image);
#endif

