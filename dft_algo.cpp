#include "dft_algo.h"


void ShiftDFT(cv::Mat *in)
{
    // divide image in 4 quadrants
    int cx = in->cols/2;
    int cy = in->rows/2;
    cv::Mat q0(*in, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(*in, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(*in, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(*in, cv::Rect(cx, cy, cx, cy));
    // swap quadrant 0-3 and 1-2
    cv::Mat temp;
    q0.copyTo(temp);
    q3.copyTo(q0);
    temp.copyTo(q3);
    q1.copyTo(temp);
    q2.copyTo(q1);
    temp.copyTo(q2);
}


void CreateOptimalImageForDFT(const cv::Mat &in, cv::Mat *out)
{
    // create image with optimal size (add 0 on the boarders)
    int M = cv::getOptimalDFTSize(in.rows);
    int N = cv::getOptimalDFTSize(in.cols);
    cv::Mat padded;
    cv::copyMakeBorder(in, padded, 0, M-in.rows, 0, N-in.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
    // create complex image for dft
    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    merge(planes, 2, *out);
}


void ComputeSpectre(const cv::Mat &in, cv::Mat *out)
{
    std::vector<cv::Mat> planes;
    split(in, planes);
    ComputeSpectre(planes, out);
}


void ComputeSpectre(const std::vector<cv::Mat> &in, cv::Mat *out)
{
    // out = sqrt( real^2 + complex^2 )
    cv::sqrt( in[0].mul(in[0]) + in[1].mul(in[1]) , *out);
}
