// SFVideoProcessor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// https://www.youtube.com/watch?v=2FYm3GOonhk
int main()
{
    std::string path = "Resources/testvideo.mp4";
    cv::VideoCapture cap(path);

    while (true) {
        cv::Mat frame;
        bool ret = cap.read(frame);
        if (!ret) {
            std::cout << "end of video";
            break;
        }

        imshow("Video Frame", frame);
        char key = cv::waitKey(10);
        if (key == 'q') {
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}