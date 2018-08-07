#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\opencv.hpp>
#include "ImageProcess.h"
#include "User.h"
void Help()
{
	std::cout << "Pomoc" << std::endl;
	std::cout << "Poprawny format wpisywanych danych to: -i nazwa pliku wejsciowego -numerfiltru" << std::endl;
	std::cout << "1-filtr czarnobialy 2-sepia 3-wykrywanie krawedzi 4-jasnosc i contrast 5-wygladzanie" << std::endl;
}
int CheckTerminal(int argc, char *argv[], string & inputname, int & number, string & outputname)
{
	int ok = 0; 
	if(argc <= 7)
	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == string("-h"))
		{
			return 1;
		}
		if (string(argv[i]) == string("-i"))
		{
			inputname = string(argv[i + 1]);
			ok++;
		}
		if (string(argv[i]) == string("-o"))
		{
			outputname = string(argv[i + 1]);
			ok++;
		}
		if (string(argv[i]) == string("-n"))
		{
			number = int(argv[i + 1]);
			ok++;
		}
	}
	if (ok == 3)
	{
		return 0;
	}
	else
	{
		return 1; 
	}
}
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