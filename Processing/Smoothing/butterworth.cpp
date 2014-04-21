#include "butterworth.h"

Butterworth::Butterworth()
{
}


void Butterworth::Process(cv::Mat in, cv::Mat out)
{
    /*
    std::cout << "\nCV_8UC3 = " << CV_8UC3 << std::endl;
    std::cout << "channels = " << in.channels() << std::endl;
    std::cout << "type = " << in.type() << std::endl;

//    cv::Mat in2;
//    in.convertTo(in2, CV_32FC3);
//    std::cout << "channels = " << in.channels() << std::endl;
//    std::cout << "type = " << in.type() << std::endl;

//    cv::imshow("in", in);
//    cv::imshow("in2", in2);
//    cv::waitKey(0);

    cv::Mat planesIn[3];
    split(in, planesIn);
    cv::Mat planesOut[3];
    for(int i=0; i<3; ++i)
    {
        planesIn[i].convertTo(planesIn[i], CV_32F, 1/255.0);

        dft(planesIn[i], planesOut[i]);
        idft(planesOut[i], planesOut[i]);

        cv::imshow("planesIn[i]", planesIn[i]);
        cv::imshow("planesOut[i]", planesOut[i]);
        cv::waitKey(0);


    }*/

    cv::Mat planesIn[3];
    split(in, planesIn);
    cv::Mat planesOut[3];
    for(int i=0; i<3; ++i)
    {
        planesIn[i].convertTo(planesIn[i], CV_32F, 1/255.0);
        cv::imshow("planesIn[i]", planesIn[i]);

        cv::Mat fft;
        cv::dft(planesIn[i], fft, cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);

        cv::Mat planes[2];
        split(fft, planes);
        planes[0].convertTo(planes[0], CV_8U);
        cv::imshow("planes[0]", planes[0]);
        planes[1].convertTo(planes[1], CV_8U);
        cv::imshow("planes[1]", planes[1]);
        std::cout << "channels = " << fft.channels() << std::endl;
        std::cout << "type = " << fft.type() << std::endl;

        cv::dft(fft, planesOut[i], cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
        cv::imshow("planesOut[i]", planesOut[i]);

        cv::waitKey(0);
    }
    merge(planesOut, 3, out);

//    cv::imshow("in", in);
//    cv::imshow("out", out);
//    cv::waitKey(0);
}
