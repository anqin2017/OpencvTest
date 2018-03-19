//#include <opencv2\opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//#define WINDOW_NAME "THE PROJECT"
//int g_ThresHoldValue = 100;
//int g_ThresHoldType = 3;
//Mat g_srcImage, g_grayImage, g_dstImage;
//
//static void ShowHelpText();

//void on_Threshold(int, void*);
//
//int main1()
//{
//	g_srcImage = imread("C:\\Users\\AQ\\Desktop\\image\\89641.jpg");
//	if (!g_srcImage.data)
//	{
//		cerr << "null image " << endl;
//		return -1;
//	}
//	//cout << g_srcImage.type() << endl;
//	cvtColor(g_srcImage, g_grayImage, CV_BGR2GRAY);
//	cvNamedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
//	imshow(WINDOW_NAME, g_grayImage);	
//	createTrackbar("modle", WINDOW_NAME, &g_ThresHoldType, 4, on_Threshold);
//	createTrackbar("value", WINDOW_NAME, &g_ThresHoldValue, 255, on_Threshold);
//	on_Threshold(0, 0);
//	while (1)
//	{
//		int key;
//		key = waitKey(0);
//		if ((char)key == 27)
//		{
//			break;
//		}
//	}
//	return 0;
//}
//
//void on_Threshold(int, void*)
//{
//	threshold(g_grayImage, g_dstImage, g_ThresHoldValue, 255, g_ThresHoldType);
//	imshow(WINDOW_NAME, g_dstImage);
//}
//
