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

    cv::Mat gray;
    cv::cvtColor(in, gray, CV_BGR2GRAY);
    cv::imshow("gray", gray);
    std::cout << "smeuh = " << gray.channels() << std::endl;
//    cv::imshow("gray", gray);

//    cv::Size dftSize;
//    // calculate the size of DFT transform
//    dftSize.width = cv::getOptimalDFTSize(gray.cols);
//    dftSize.height = cv::getOptimalDFTSize(gray.rows);
//    // allocate temporary buffers and initialize them with 0's
//    cv::Mat temp(dftSize, gray.type(), cv::Scalar::all(0));
//    // copy to the top-left corners of temp
//    cv::Mat roi(temp, cv::Rect(0,0,gray.cols,gray.rows));
//    gray.copyTo(roi);
//    // use "nonzeroRows" hint for faster processing
//    dft(temp, temp, 0, gray.rows); erreur sur dft
//    cv::imshow("temp dft", temp);

    int M = cv::getOptimalDFTSize( gray.rows );
    int N = cv::getOptimalDFTSize( gray.cols );

    cv::Mat padded;
    cv::copyMakeBorder(gray, padded, 0, M - gray.rows, 0, N - gray.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
    cv::Mat planes[2];
    planes[0] = cv::Mat_<float>(padded);
    planes[1] = cv::Mat::zeros(padded.size(), CV_32F);

    cv::Mat fft;
    merge(planes, 2, fft);
    // do the DFT
    dft(fft, fft);

    cv::Mat planesFFT[2];
    split(fft, planesFFT);
//    cv::imshow("planesFFT 0", planesFFT[0]);
//    cv::imshow("planesFFT 1", planesFFT[1]);

    // http://sparis.free.fr/Cours_Multimedia/TP0.pdf
    // page 3
    cv::Mat imFreq, p0, p1;
    cv::pow(planesFFT[0], 2, p0);
    cv::pow(planesFFT[1], 2, p1);
    cv::sqrt(p0+p1,imFreq);
    imFreq.convertTo(imFreq, CV_8U, 1/255.);
    cv::imshow("imFreq", imFreq);

cv::waitKey(0);
    return;

    cv::Mat planesIn[3];
    split(in, planesIn);
    cv::Mat planesOut[3];
    for(int i=0; i<3; ++i)
    {
        planesIn[i].convertTo(planesIn[i], CV_32F, 1/255.0);
        cv::imshow("planesIn[i]", planesIn[i]);

        //
        cv::Size dftSize;
        // calculate the size of DFT transform
        dftSize.width = cv::getOptimalDFTSize(planesIn[i].cols);
        dftSize.height = cv::getOptimalDFTSize(planesIn[i].rows);
        // allocate temporary buffers and initialize them with 0's
        cv::Mat temp(dftSize, planesIn[i].type(), cv::Scalar::all(0));
        // copy to the top-left corners of temp
        cv::Mat roi(temp, cv::Rect(0,0,planesIn[i].cols,planesIn[i].rows));
        planesIn[i].copyTo(roi);
        // use "nonzeroRows" hint for faster processing
        dft(temp, temp, 0, planesIn[i].rows);
        cv::imshow("temp", temp);
        //

        cv::Mat fft;
        cv::dft(planesIn[i], fft, cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);

        cv::Mat planes[2];
        split(fft, planes);

        planes[0].convertTo(planes[0], CV_8U);
        cv::imshow("planes[0]", planes[0]);

        planes[1].convertTo(planes[1], CV_8U);
        cv::imshow("planes[1]", planes[1]);

        cv::dft(fft, planesOut[i], cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
        cv::imshow("planesOut[i]", planesOut[i]);

        cv::waitKey(0);
    }
    merge(planesOut, 3, out);

//    cv::imshow("in", in);
//    cv::imshow("out", out);
//    cv::waitKey(0);
}
