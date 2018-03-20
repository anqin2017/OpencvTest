//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//#include <math.h>
//using namespace cv;
//using namespace std;
//const char* harris_win = "Custom Harris Corners Detector";
//const char* shitomasi_win = "Custom Shi-Tomasi Corners Detector";
//Mat src, gray_src;
//// harris corner response
//Mat harris_dst, harrisRspImg;
//double harris_min_rsp;
//double harris_max_rsp;
//// shi-tomasi corner response
//Mat shiTomasiRsp;
//double shitomasi_max_rsp;
//double shitomasi_min_rsp;
//int sm_qualitylevel = 30;
//// quality level
//int qualityLevel = 50;
//int max_count = 100;
//void CustomHarris_Demo(int, void*);
//void CustomShiTomasi_Demo(int, void*);
//int main(int argc, char** argv)
//{
//	src = imread("C:/Users/pvt1001/Desktop/image1/4.jpg");
//	if (src.empty()) {
//		printf("could not load image...\n");
//		return -1;
//	}
//	namedWindow("input image", CV_WINDOW_AUTOSIZE);
//	imshow("input image", src);
//	cvtColor(src, gray_src, CV_BGR2GRAY);
//	cout << " rows: " << gray_src.rows << "cols: " << gray_src.cols << "channels: " << gray_src.channels() << endl;
//	int blockSize = 3;
//	int ksize = 3;
//	double k = 0.04;
//	harris_dst = Mat::zeros(src.size(), CV_32FC(6));
//	harrisRspImg = Mat::zeros(src.size(), CV_32FC1);
//	//计算响应
//	cornerEigenValsAndVecs(gray_src, harris_dst, blockSize, ksize, 4);
//	cout << " rows: " << harris_dst.rows << "cols: " << harris_dst.cols << "channels: " << harris_dst.channels() << endl;
//	for(int i = 0 ; i < harris_dst.rows ; ++i)
//	{
//		for (int j = 0; j < harris_dst.cols; ++j)
//		{
//			double lambda1 = harris_dst.at<Vec6f>(i, j)[0];
//			double lambda2 = harris_dst.at<Vec6f>(i, j)[1];
//			harrisRspImg.at<float>(i, j) = lambda1*lambda2 - k * pow((lambda1 + lambda2), 2);
//		}
//	}
//	minMaxLoc(harrisRspImg, &harris_min_rsp, &harris_max_rsp, 0, 0, Mat());
//	//cout << "max value : " << harris_max_rsp << "min value : " << harris_min_rsp << endl;
//	namedWindow(harris_win, WINDOW_AUTOSIZE);
//	createTrackbar("quality value :", harris_win, &qualityLevel, max_count, CustomHarris_Demo);
//	CustomHarris_Demo(0, 0);
//	// 计算最小特征值
//	shiTomasiRsp = Mat::zeros(src.size(), CV_32FC1);
//	cornerMinEigenVal(gray_src, shiTomasiRsp, blockSize, ksize, 4);
//	minMaxLoc(shiTomasiRsp, &shitomasi_min_rsp, &shitomasi_max_rsp, 0, 0, Mat());
//	namedWindow(shitomasi_win, CV_WINDOW_AUTOSIZE);
//	createTrackbar("Quality:", shitomasi_win, &sm_qualitylevel, max_count, CustomShiTomasi_Demo);
//	CustomShiTomasi_Demo(0, 0);
//	waitKey(0);
//	return 0;
//}
//
//void CustomHarris_Demo(int, void*)
//{
//	if (qualityLevel < 10)
//	{
//		qualityLevel = 10;
//	}
//	Mat resultImg = src.clone();
//	float t = harris_min_rsp + (((double)qualityLevel) / max_count)*(harris_max_rsp - harris_min_rsp);
//	for (int row = 0; row < src.rows; row++)
//    {
//		for (int col = 0; col < src.cols; col++) 
//		{
//			float v = harrisRspImg.at<float>(row, col);
//			if (v > t) 
//			{
//				circle(resultImg, Point(col, row), 2, Scalar(0, 0, 255), 2, 8, 0);
//			}
//		}
//	}
//	imshow(harris_win, resultImg);
//}
//
//void CustomShiTomasi_Demo(int, void*)
//{
//	if (sm_qualitylevel < 20) {
//		sm_qualitylevel = 20;
//	}
//
//	Mat resultImg = src.clone();
//	float t = shitomasi_min_rsp + (((double)sm_qualitylevel) / max_count)*(shitomasi_max_rsp - shitomasi_min_rsp);
//	for (int row = 0; row < src.rows; row++) {
//		for (int col = 0; col < src.cols; col++) {
//			float v = shiTomasiRsp.at<float>(row, col);
//			if (v > t) {
//				circle(resultImg, Point(col, row), 2, Scalar(0, 0, 255), 2, 8, 0);
//			}
//		}
//	}
//	imshow(shitomasi_win, resultImg);
//}