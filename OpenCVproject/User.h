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
/** Function showing picture
@author Paulina Urbas
@date 10.07.2018
*/
void ShowPicture(const Image & input, const string Info, int number);
/** Function printing help
@author Paulina Urbas
@date 10.07.2018
*/
void Help();
/** Function checking terminal
@author Paulina Urbas
@date 10.07.2018
@param int, char *, string
@return int
*/
int CheckTerminal(int argc, char *argv[], string & inputname);
/** Function checking number of filtr and coverting
@date 10.07.2018
@param char *, Image *
@return int
*/
#endif
