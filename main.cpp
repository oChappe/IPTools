#include <iostream>
#include <limits>

#include "Processing/processing.h"
#include "Processing/Smoothing/butterworth.h"
#include "Processing/Smoothing/laplacian.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{

    Processing *algo;
//    algo = new Butterworth;
    algo = new Laplacian;

    std::vector<std::string> files;
    files.push_back("C:\\Users\\oliyo_000\\Pictures\\2013.08.26 Vacances\\DSC_0545.jpg");
//    files.push_back("C:\\Users\\oliyo_000\\Pictures\\mizayaki-character-portrait-large.jpg");
    for(unsigned i=0; i<files.size(); ++i)
    {
        cv::Mat in = cv::imread(files[i], CV_LOAD_IMAGE_COLOR);
        cv::Mat out;
        algo->process(in, &out);
    }


//    Laplacian la; // 10 10
//    la.setSize(10,5); // 10 5
//    la.setSize(10,-1); // 10 10
//    la.setSize(7,3); // 7 3
//    cv::Mat in = (cv::Mat_<float>(3,4) << 1, 1, 1, 1, 1, 19, 1, 1, 1, 1, 1, 1);
//    cv::Mat out;
//    la.process(in, &out);
//    std::cout << "\n" << in << "\n\n";
//    std::cout << out << std::endl;

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
