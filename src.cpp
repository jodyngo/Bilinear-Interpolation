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

	/// Set the dstimage the same type and size as src
	Mat result_img = Mat::zeros(image.rows, image.cols, image.type());

	Point2f srcTri[3];
	Point2f dstTri[3];
	Mat warp_mat(2, 3, CV_32FC1);
	
	/// Set your 3 points to calculate the Affine Transform
	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols - 1, 0);
	srcTri[2] = Point2f(0, src.rows - 1);
	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
	dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
	dstTri[2] = Point2f(src.cols*0.15, src.rows*0.7);

	/// Get the Affine Transform
	warp_mat = getAffineTransform(srcTri, dstTri);

	/// Apply the Affine Transform just found to the srcimage
	warpAffine(src, warp_dst, warp_mat, warp_dst.size());

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
