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

    std::vector<std::string> files;
    files.push_back("C:\\Users\\oliyo_000\\Pictures\\2013.08.26 Vacances\\DSC_0545.jpg");
//    files.push_back("C:\\Users\\oliyo_000\\Pictures\\mizayaki-character-portrait-large.jpg");
    for(unsigned i=0; i<files.size(); ++i)
    {
        cv::Mat in = cv::imread(files[i], CV_LOAD_IMAGE_COLOR);
        cv::Mat out;
        algo->Process(in, &out);
    }

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
