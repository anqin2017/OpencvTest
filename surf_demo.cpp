#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

int main(int argc, char** argv)
{
	Mat src = imread("C:/Users/pvt1001/Desktop/image1/4.jpg", IMREAD_GRAYSCALE);
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	int minHessian = 1000;
	Ptr<SURF> dector = SURF::create(minHessian);
	vector<KeyPoint> keypoints;
	dector->detect(src, keypoints, Mat());
	cout << "keypoint size: " << keypoints.size() << endl;
	Mat key_point_image;
	drawKeypoints(src, keypoints, key_point_image, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	imshow("keypoints image", key_point_image);
	waitKey(0);
	return 0;
}