#include "processing.h"

Processing::Processing()
{
}


void Processing::process(const cv::Mat &in, cv::Mat *out)
{
    cv::imshow("Process in", in);
    int method = 2;

    if( method == 1 )
    {
        // convert in gray color
        cv::Mat gray;
        cv::cvtColor(in, gray, CV_BGR2GRAY);
        applyAlgo(gray, out);
    }
    else if( method == 2 )
    {
        // apply algo for each canal
        int nbC = in.channels();
        std::vector<cv::Mat> planesIn;
        std::vector<cv::Mat> planesOut(nbC);
        split(in, planesIn);
//        for(const auto &plane:planesIn)
//        {
//            ApplyAlgo(plane, &planesOut[i]);
//        }
        for(int i=0; i<nbC; ++i)
        {
            applyAlgo(planesIn[i], &planesOut[i]);
        }
        merge(planesOut, *out);
    }


    cv::imshow("out", *out);
    cv::waitKey(0);
}
