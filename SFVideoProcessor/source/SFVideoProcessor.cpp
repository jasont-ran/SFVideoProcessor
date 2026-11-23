// SFVideoProcessor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// https://www.youtube.com/watch?v=2FYm3GOonhk


void VideoProcessor(std::string path);

void ImageProcessor(std::string path);

void getPlayerOneHealthBar(cv::Mat frame);

void getPlayerTwoHealthBar(cv::Mat frame);

int main()
{
    std::string videoPath = "Resources/testvideo.mp4";
    std::string imagePath = "Resources/test.jpg";
    //VideoProcessor(path);

    ImageProcessor(imagePath);

    return 0;
}

void VideoProcessor(std::string path) {
    cv::VideoCapture cap(path);

    while (true) {
        cv::Mat frame;
        bool ret = cap.read(frame);
        if (!ret) {
            std::cout << "End of video";
            break;
        }

        cv::imshow("Video Frame", frame);

        char key = cv::waitKey(10);
        if (key == 'q') {
            break;
        }
    }
    cap.release();
    cv::destroyAllWindows();
}

void ImageProcessor(std::string path) {
    cv::Mat img = cv::imread(path);
    //cv::imshow("Image", img);

    getPlayerOneHealthBar(img);
    //getPlayerTwoHealthBar(img);

    cv::waitKey(0);

    cv::destroyAllWindows();

}


void getPlayerOneHealthBar(cv::Mat frame) {
    //cv::Rect player1Health(165, 58, 690, 19);

    int x = 167;
    int y = 63;
    int rectWidth = 685;
    int rectHeight = 19;
    cv::Rect player1Health(x, y, rectWidth, rectHeight);

    cv::Mat p1Health = frame(player1Health);
    cv::imshow("Player 1 Health", p1Health);



    cv::Mat hsv;
    cv::cvtColor(p1Health, hsv, cv::COLOR_BGR2HSV);

    cv::Mat mask;
    cv::Scalar lower(140, 50, 50);
    cv::Scalar upper(179, 255, 255);

    cv::inRange(hsv, lower, upper, mask);
    cv::imshow("Health Mask", mask);

}

void getPlayerTwoHealthBar(cv::Mat frame) {
    cv::Rect player2Health(1045, 52, 710, 36);
    cv::Mat p2Health = frame(player2Health);
    cv::imshow("Player 2 Health", p2Health);
}