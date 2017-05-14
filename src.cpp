#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	Mat image = imread("C:/Users/westbro/Desktop/Lenna.png");

	double h_rate = 2.0;
	double w_rate = 2.0;

	int h = image.rows*h_rate;
	int w = image.cols*w_rate;

	Mat result_img(h, w, CV_8UC3, Scalar(0));

	for (int y = 0; y < result_img.rows - 1; y++) {
		for (int x = 0; x < result_img.cols - 1; x++) {
			int px = (int)(x / w_rate);
			int py = (int)(y / h_rate);

			if (px >= image.cols - 1 || py >= image.rows - 1) break;

			double fx1 = (double)x / (double)w_rate - (double)px;
			double fx2 = 1 - fx1;
			double fy1 = (double)y / (double)h_rate - (double)py;
			double fy2 = 1 - fy1;

			double w1 = fx2*fy2;
			double w2 = fx1*fy2;
			double w3 = fx2*fy1;
			double w4 = fx1*fy1;

			Vec3b p1 = image.at<Vec3b>(py, px);
			Vec3b p2 = image.at<Vec3b>(py, px + 1);
			Vec3b p3 = image.at<Vec3b>(py + 1, px);
			Vec3b p4 = image.at<Vec3b>(py + 1, px + 1);
			result_img.at<Vec3b>(y, x) = w1*p1 + w2*p2 + w3*p3 + w4*p4;
		}
	}

	/// Create Windows
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("result Image", WINDOW_AUTOSIZE);

	/// Show stuff
	imshow("Original Image", image);
	imshow("result Image", result_img);

	/// Wait until user press some key
	waitKey(0);
	return 0;
}
