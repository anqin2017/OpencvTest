//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//Mat src, gray_src;
//int thresh = 50;
//int max_count = 255;
//const char* output_title = "HarrisCornerDetection Result";
//void Harris_Demo(int, void*);
//int main(int argc, char** argv) {
//
//	src = imread("C:/Users/pvt1001/Desktop/image1/building.jpg");
//	if (src.empty()) {
//		printf("could not load image...\n");
//		return -1;
//	}
//	namedWindow("input image", CV_WINDOW_AUTOSIZE);
//	imshow("input image", src);
//
//	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
//	cvtColor(src, gray_src, COLOR_BGR2GRAY);
//	createTrackbar("Threshold:", output_title, &thresh, max_count, Harris_Demo);
//	Harris_Demo(0, 0);
//	waitKey(0);
//	return 0;
//}
//
//void Harris_Demo(int, void*)
//{
//	Mat dst, norm_dst, normScaleDst;
//	dst = Mat::zeros(gray_src.size(), CV_32FC1);
//	int blockSize = 2;
//	int kSize = 3;
//	double k = 0.04;
//	cornerHarris(gray_src, dst, blockSize, kSize, k, BORDER_DEFAULT);
//	//归一化
//	normalize(dst, norm_dst, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
//	////将归一化后的图线性变换成8位无符号整型   
//	convertScaleAbs(norm_dst, normScaleDst);
//	Mat resultImage = src.clone();
//	for (int i = 0; i < resultImage.rows; ++i)
//	{
//		uchar* currentRow = normScaleDst.ptr(i);
//		for (int j = 0; j < resultImage.cols; ++j)
//		{
//			int value =(int) *currentRow;
//			if (value > thresh)
//			{
//				circle(resultImage, Point(i, j), 5, Scalar(0, 0, 255), 2,8,0);
//			}
//			currentRow++;
//		}
//		
//	}
//	imshow(output_title, resultImage);
//}
//
