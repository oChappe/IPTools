#include "butterworth.h"

Butterworth::Butterworth()
{
}


void Butterworth::ApplyAlgo(const cv::Mat &in, cv::Mat *out)
{
    cv::imshow("in", in);

//    double mini, maxi;
//    cv::minMaxIdx(in, &mini, &maxi);
//    std::cout << "in mini = " << mini << std::endl;
//    std::cout << "in maxi = " << maxi << std::endl;


    int M = cv::getOptimalDFTSize( in.rows );
    int N = cv::getOptimalDFTSize( in.cols );

    cv::Mat padded;
    cv::copyMakeBorder(in, padded, 0, M - in.rows, 0, N - in.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
    cv::Mat planes[2];
    planes[0] = cv::Mat_<float>(padded);
    planes[1] = cv::Mat::zeros(padded.size(), CV_32F);

    cv::Mat fft;
    merge(planes, 2, fft);
    // do the DFT
    dft(fft, fft);

//    cv::minMaxIdx(fft, &mini, &maxi);
//    std::cout << "fft mini = " << mini << std::endl;
//    std::cout << "fft maxi = " << maxi << std::endl;

    cv::Mat planesFFT[2];
    split(fft, planesFFT);
//    cv::imshow("planesFFT 0", planesFFT[0]);
//    cv::imshow("planesFFT 1", planesFFT[1]);


//    cv::minMaxIdx(planesFFT[0], &mini, &maxi);
//    std::cout << "real mini = " << mini << std::endl;
//    std::cout << "real maxi = " << maxi << std::endl;

//    cv::minMaxIdx(planesFFT[1], &mini, &maxi);
//    std::cout << "imag mini = " << mini << std::endl;
//    std::cout << "imag maxi = " << maxi << std::endl;


    // http://sparis.free.fr/Cours_Multimedia/TP0.pdf
    // page 3
    cv::Mat imFreq, p0, p1;
    cv::pow(planesFFT[0], 2, p0);
    cv::pow(planesFFT[1], 2, p1);
    cv::sqrt(p0+p1,imFreq);
    imFreq.convertTo(imFreq, CV_8U, 1/255.);

    // shift
    int cx = imFreq.cols/2;
    int cy = imFreq.rows/2;
    cv::Mat q0(imFreq, cv::Rect(0, 0, cx, cy));
    cv::Mat q1(imFreq, cv::Rect(cx, 0, cx, cy));
    cv::Mat q2(imFreq, cv::Rect(0, cy, cx, cy));
    cv::Mat q3(imFreq, cv::Rect(cx, cy, cx, cy));
    cv::Mat temp;
    q0.copyTo(temp);
    q3.copyTo(q0);
    temp.copyTo(q3);
    q1.copyTo(temp);
    q2.copyTo(q1);
    temp.copyTo(q2);

    cv::imshow("imFreq", imFreq);


//    cv::dft(planesIn[i], fft, cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);
    cv::dft(fft, *out, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);

    std::cout << "\nfft type = " << fft.type() << std::endl;
    std::cout << "fft channels = " << fft.channels() << std::endl;
    std::cout << "fft rows = " << fft.rows << std::endl;
    std::cout << "fft cols = " << fft.cols << std::endl;

    std::cout << "\nout type = " << out->type() << std::endl;
    std::cout << "out channels = " << out->channels() << std::endl;
    std::cout << "out rows = " << out->rows << std::endl;
    std::cout << "out cols = " << out->cols << std::endl;

//    cv::waitKey(0);


}
