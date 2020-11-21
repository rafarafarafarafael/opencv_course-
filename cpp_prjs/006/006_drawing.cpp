#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

void showImage(const std::string & win, cv::Mat & img){
    cv::namedWindow(win);
    cv::imshow(win, img);
    cv::waitKey();
    cv::destroyAllWindows();
}

int main(){
    const std::string img_path = ".\\images\\boy.jpg";
    cv::Mat img = cv::imread(img_path);

    showImage("Boy", img);

    // drawing a line
    const cv::Point pt0 = cv::Point(200, 100), pt1 = cv::Point(280, 100);
    const cv::Scalar GREEN = cv::Scalar(0, 255, 0);
    cv::line(img, pt0, pt1, GREEN, 2, cv::LINE_AA);
    showImage("Boy with line", img);

    // drawing an ellipse
    const cv::Point ctr0 = cv::Point(240, 125), ax0 = cv::Point(100, 50), ax1 = cv::Point(50, 100);
    const cv::Scalar RED = cv::Scalar(0, 0, 255), BLUE = cv::Scalar(255, 0, 0);
    cv::ellipse(img, ctr0, ax0, 0, 0, 360, RED, 2, cv::LINE_AA);
    cv::ellipse(img, ctr0, ax1, 0, 0, 360, BLUE, 2, cv::LINE_AA);
    showImage("Boy with line and ellipses", img);

    // drawing a circle
    int rad0 = 150;
    cv::circle(img, ctr0, rad0, GREEN, 2, cv::LINE_AA);
    showImage("Boy lines circle and ellipses", img);

    // drawing a rectangle
    const cv::Point pt2 = cv::Point(170, 50), pt3 = cv::Point(310, 200);
    const cv::Scalar MAGENTA = cv::Scalar(255, 0, 255);
    cv::rectangle(img, pt2, pt3, MAGENTA, 3, cv::LINE_8);
    showImage("All with a rectangle now", img);

    return 0;
}