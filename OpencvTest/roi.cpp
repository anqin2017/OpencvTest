//#include <opencv2\opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//#define input "input image"
//#define output "output image"
//Mat g_srcImage, g_dstImage;
//Rect g_rect = Rect(0, 0, 0, 0);
//Point g_origin = Point(0, 0);
//bool g_drawing = false; 
//
//void OnMouseMove(int event, int x, int y, int flags, void* param);//回调函数，操作鼠标时触发回调
//
//int main()
//{
//	g_srcImage = imread("C:\\Users\\pvt1001\\Desktop\\image1\\1.jpg");
//	if (!g_srcImage.data)
//	{
//		cerr << "null image!" << endl;
//		return -1;
//	}
//	imshow(input, g_srcImage);
//	cvSetMouseCallback(input, OnMouseMove, NULL);
//	waitKey(0);
//	return 0;
//}
//
//void OnMouseMove(int event, int x, int y, int flags, void* param)
//{
//	//鼠标左键按下
//	if (event == CV_EVENT_LBUTTONDOWN && event != CV_EVENT_MOUSEMOVE)
//	{
//		g_drawing = true;
//		g_origin = cvPoint(x, y);
//		cout << "g_origin" << g_origin.x << g_origin.y << endl;
//		g_rect = cvRect(x, y, 0, 0);
//	}
//	//鼠标移动
//	else if ((event == CV_EVENT_MOUSEMOVE) && (flags && CV_EVENT_FLAG_LBUTTON))
//	{
//		if (g_drawing)
//		{
//			g_rect.x = MIN(g_origin.x, x);
//			g_rect.y = MIN(g_origin.y, y);// 获取最左边的坐标
//			g_rect.height = abs(x - g_origin.x);
//			g_rect.width = abs(y - g_origin.y);
//		}
//	}
//	// 鼠标抬起
//	else if (event == CV_EVENT_LBUTTONUP)
//	{
//		g_drawing = false;
//		if (g_rect.height == 0 && g_rect.width == 0)
//		{
//			cerr << "you don't choose any rectangle area!!!" << endl;
//			return;
//		}
//		g_srcImage(g_rect).copyTo(g_dstImage);
//		Mat tempImage;
//		tempImage = g_srcImage.clone();
//		rectangle(tempImage, Point(g_rect.x, g_rect.y), Point(g_rect.x + g_rect.height, g_rect.y + g_rect.width), cvScalar(0, 255, 0));
//		imshow(output, g_dstImage);
//		imshow(input, tempImage);
//		waitKey(0);
//	}
//}