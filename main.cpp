#include <iostream>
#include <limits>

#include "Processing/processing.h"
#include "Processing/Smoothing/butterworth.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    Processing *algo;

    algo = new Butterworth;
    cv::Mat in = cv::imread("C:\\Users\\oliyo_000\\Pictures\\2013.08.26 Vacances\\DSC_0545.jpg", CV_LOAD_IMAGE_COLOR);
    cv::imshow( "Display window", in );
    cv::waitKey(0);
    cv::Mat out;
    algo->Process(in, out);

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
