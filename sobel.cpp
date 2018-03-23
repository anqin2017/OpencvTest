#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

#define WINDOW_NAME "THE PROJECT"
Mat g_srcImage, g_xImage, g_yImage, g_dstImage;


int main()
{
	g_srcImage = imread("C:\\Users\\AQ\\Desktop\\image\\89641.jpg");
	if (!g_srcImage.data)
	{
		cerr << "null image " << endl;
		return -1;
	}
	//imshow(WINDOW_NAME, g_srcImage);
	cvtColor(g_srcImage, g_srcImage, CV_BGR2GRAY);
	// x direction
	Sobel(g_srcImage, g_xImage, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_xImage,g_xImage);
	imshow("x_image", g_xImage);
	//y direction
	Sobel(g_srcImage, g_yImage, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_yImage, g_yImage);
	imshow("y_image", g_yImage);
	//combine direction
	addWeighted(g_xImage, 0.6, g_yImage, 0.4, 0, g_dstImage);
	imshow("combine", g_dstImage);
	waitKey(0);
	return 0;
}
