#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
    cv::Mat img = cv::imread("image.JPG");
    cv::imshow("ok", img);
    cv::waitKey(0);
    return 0;
}