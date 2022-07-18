#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main()
{
    /// 
    /// Read an image
    /// 
    string path = "image.JPG";
    Mat img = imread(path);
    imshow("ok", img);
    waitKey(0);
    
    /// 
    /// Read a video
    /// 
    string path_video = "video.mp4";
    VideoCapture cap(path_video);
    Mat frame;

    while (true) {
        cap.read(frame);
        imshow("Image", frame);
        waitKey(1);
    }


    return 0;
}   
