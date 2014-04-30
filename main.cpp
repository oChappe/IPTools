#include <iostream>
#include <limits>

#include "Processing/processing.h"
#include "Processing/Smoothing/butterworth.h"
#include "Processing/Smoothing/laplacian.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    std::cout << "\n\n";

    Processing *algo;
//    algo = new Butterworth;
    algo = new Laplacian;

    std::vector<std::string> files;
    files.push_back("C:\\Users\\oliyo_000\\Pictures\\2013.08.26 Vacances\\DSC_0545.jpg");
//    files.push_back("C:\\Users\\oliyo_000\\Pictures\\mizayaki-character-portrait-large.jpg");
/*    for(unsigned i=0; i<files.size(); ++i)
    {
        cv::Mat in = cv::imread(files[i], CV_LOAD_IMAGE_COLOR);
        cv::Mat out;
        algo->process(in, &out);
    }
*/

//    Laplacian la(3, 4); // 10 10
//    la.setSize(10,5); // 10 5
//    la.setSize(10,0); // 10 10
//    la.setSize(7,3); // 7 3
//    la.setSize(9); // 7 3
//    cv::Mat in = (cv::Mat_<float>(3,4) << 1, 1, 7, 1, 1, 19, 1, 1, 1, -2, 1, 1);
//    cv::Mat out;
//    la.process(in, &out);
//    std::cout << "\n" << in << "\n\n";
//    std::cout << out << std::endl;

//    cv::blur(in, out, cv::Size(4,3));
//    std::cout << "\n\n" << in << "\n\n";
//    std::cout << out << std::endl;

    // essai stretched mesh grid ( http://www3.nd.edu/~gtryggva/CFD-Course/2011-Lecture-25.pdf )
    float L = 2.0f; // 2
    float xc = 1.0f; // 1
    float A = 2.5f; // 2.5
    cv::Mat in = cv::imread(files[0], CV_LOAD_IMAGE_COLOR);
    cv::cvtColor(in, in, CV_BGR2GRAY);
    cv::normalize(in, in, 0.0f, 1.0f, cv::NORM_MINMAX, CV_32F);
    cv::Mat out = cv::Mat(in.size(), CV_32F);
    double mini, maxi;
    cv::minMaxIdx(in, &mini, &maxi);
    std::cout << "\n" << mini << " - " << maxi << std::endl;
    for(int i=0; i<in.rows; ++i)
    {
        float *ptrIn = in.ptr<float>(i);
        float *ptrOut = out.ptr<float>(i);
        for(int j=0; j<in.cols; ++j)
        {
            ptrOut[j] = L * ptrIn[j] + A * (xc - L * ptrIn[j]) * ptrIn[j] * (1 - ptrIn[j]);
//            ptrOut[j] = ptrIn[j];
        }
    }
    cv::imshow("in", in);
    cv::imshow("out", out);
    cv::waitKey(0);

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    return 0;
}
