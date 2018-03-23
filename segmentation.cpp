//#include <opencv2\opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//#define input "input image"
////#define watershed "watershed image"
//Mat g_srcImage, g_waterShed;
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
//	//change the background from white to black
//	for (int i = 0; i < g_srcImage.rows; ++i)
//	{
//		for (int j = 0; j < g_srcImage.cols; ++j)
//		{
//			if (g_srcImage.at<Vec3b>(i, j) == Vec3b(255, 255, 255))
//			{
//				g_srcImage.at<Vec3b>(i, j)[0] = 0;
//				g_srcImage.at<Vec3b>(i, j)[1] = 0;
//				g_srcImage.at<Vec3b>(i, j)[2] = 0;
//			}
//		}
//	}
//	//sharpen
//	Mat kernel = (Mat_<float>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
//	Mat laplance, sharpenImage;
//	filter2D(g_srcImage, laplance, CV_32F, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
//	g_srcImage.convertTo(sharpenImage, CV_32F);
//	Mat resultImage;
//	resultImage = sharpenImage - laplance;
//	resultImage.convertTo(resultImage, CV_8UC3);
//	laplance.convertTo(laplance, CV_8UC3);
//	imshow("sharpen image", resultImage);
//	//convert to binary
//	Mat binaryImage;
//	cvtColor(resultImage, resultImage, CV_BGR2GRAY);
//	threshold(resultImage, binaryImage, 40, 255, THRESH_BINARY | THRESH_OTSU);
//	imshow("threshold image", binaryImage);
//	// distance transform
//	Mat distImage;
//	distanceTransform(binaryImage, distImage, DIST_L1, 3, 5);
//	normalize(distImage, distImage, 0, 1, NORM_MINMAX);
//	imshow("distance image", distImage);
//	//binary
//	threshold(distImage, distImage, 0, 10, THRESH_BINARY);
//	Mat kernel1 = Mat::ones(13, 13, CV_8UC1);
//	erode(distImage, distImage, kernel1, Point(-1, -1), 1, 0);
//	imshow("binary again", distImage);
//	// find contours
//	Mat contoursImage;
//	distImage.convertTo(contoursImage, CV_8U);
//	vector<vector<Point>> contours;
//	findContours(contoursImage, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
//	// draw contours
//	Mat makers = Mat::zeros(g_srcImage.size(), CV_32SC1);
//	for (int i = 0; i < contours.size(); ++i)
//	{
//		drawContours(makers, contours, i, Scalar::all(static_cast<int>(i) + 1), -1);
//	}
//	circle(makers, Point(5, 5), 3, Scalar(255, 255, 255), -1);
//	imshow("contours image", makers*1000);
//	// watershed
//	watershed(g_srcImage, makers);
//	Mat mark;
//	mark = Mat::zeros(g_srcImage.size(), CV_8U);
//	makers.convertTo(mark, CV_8UC1);
//	bitwise_not(mark, mark, Mat()); //œÒÀÿ“¿¥Œ»°∑¥£¨a = 255 - b;
//	imshow("watershed image", mark);
//	vector<Vec3b> colors;
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		int r = theRNG().uniform(0, 255);
//		int g = theRNG().uniform(0, 255);
//		int b = theRNG().uniform(0, 255);
//		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
//	}
//	// fill with color and display final result
//	Mat dst = Mat::zeros(makers.size(), CV_8UC3);
//	for (int row = 0; row < makers.rows; row++) {
//		for (int col = 0; col < makers.cols; col++) {
//			int index = makers.at<int>(row, col);
//			if (index > 0 && index <= static_cast<int>(contours.size())) {
//				dst.at<Vec3b>(row, col) = colors[index - 1];
//			}
//			else {
//				dst.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
//			}
//		}
//	}
//	addWeighted(g_srcImage, 0.2, dst, 0.8, 0, dst);
//	imshow("Final Result", dst);
//	waitKey(0);
//	return 0;
//}