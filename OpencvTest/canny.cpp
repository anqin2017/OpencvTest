//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//#define WINDOW_NAME "THE PROJECT"
//Mat g_srcImage, g_grayImage, g_dstImage;
//int g_canny_maxValue = 150;
//
//void canny_value(int, void*);
//
//int main()
//{
//	g_srcImage = imread("C:\\Users\\AQ\\Desktop\\image\\89641.jpg");
//	if (!g_srcImage.data)
//	{
//		cerr << "null image " << endl;
//		return -1;
//	}
//	//imshow(WINDOW_NAME, g_srcImage);
//	//Canny(g_srcImage, g_srcImage, 100, 50, 3);
//	cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY);
//	blur(g_grayImage, g_grayImage, Size(3, 3));
//	//Canny(g_grayImage, g_dstImage, 150, 100, 3);
//	cvNamedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
//	createTrackbar("Value", WINDOW_NAME, &g_canny_maxValue, 255, canny_value);
//	canny_value(0, 0);
//	//imshow(WINDOW_NAME, g_dstImage);
//	waitKey(0);
//	return 0;
//}
//
//void canny_value(int, void*)
//{
//	Canny(g_grayImage, g_dstImage, g_canny_maxValue, 50, 3);
//	imshow(WINDOW_NAME, g_dstImage);
//}