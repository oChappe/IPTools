#include "processing.h"

Processing::Processing()
{
}


void Processing::Process(const cv::Mat &in, cv::Mat *out)
{
    // method 1 : convert in gray color
//    cv::Mat gray;
//    cv::cvtColor(in, gray, CV_BGR2GRAY);
//    ApplyAlgo(gray, out);

//    std::cout << "\nin type = " << in.type() << std::endl;
//    std::cout << "in channels = " << in.channels() << std::endl;
    // method 2 : apply algo for each canal
    int nbC = in.channels();
//    std::cout << "in nbC = " << nbC << std::endl;
    std::vector<cv::Mat> planesIn;
    std::vector<cv::Mat> planesOut(nbC);
    split(in, planesIn);
    for(int i=0; i<nbC; ++i)
    {
        ApplyAlgo(planesIn[i], &planesOut[i]);

//        std::cout << "\nout type = " << planesOut[i].type() << std::endl;
//        std::cout << "out channels = " << planesOut[i].channels() << std::endl;
//        std::cout << "out rows = " << planesOut[i].rows << std::endl;
//        std::cout << "out cols = " << planesOut[i].cols << std::endl;
    }
//    std::cout << "\nout type = " << out.type() << std::endl;
//    std::cout << "out channels = " << out.channels() << std::endl;
    merge(planesOut, *out);
//    std::cout << "\nout type = " << out.type() << std::endl;
//    std::cout << "out channels = " << out.channels() << std::endl;
//    std::cout << "out rows = " << out.rows << std::endl;
//    std::cout << "out cols = " << out.cols << std::endl;

//    out.convertTo(out, CV_32FC3);
    cv::imshow("out", *out);
    cv::waitKey(0);
}
