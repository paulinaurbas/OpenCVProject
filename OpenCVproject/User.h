#ifndef USER_H
#define USER_H
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "ImageProcess.h"
using namespace std;
using namespace cv;
 
void ShowPicture(const Image & input, const string Info, int number);

#endif
