#include "butterworth.h"
#include "dft_algo.h"

Butterworth::Butterworth(float wc, float n) :
    m_wc(wc),
    m_n(n)
{
}


void Butterworth::applyAlgo(const cv::Mat &in, cv::Mat *out)
{
    cv::imshow("in", in);

    // create optimal image size
    cv::Mat fft;
    createOptimalImageForDFT(in, &fft);
    // compute DFT
    dft(fft, fft);
    shiftDFT(&fft);

    // display spectre
//    cv::Mat spectre;
//    ComputeSpectre(fft, &spectre);
//    spectre.convertTo(spectre, CV_8U, 1/255.);
//    cv::imshow("spectre fft", spectre);

    // update filter
    if( fft.size() != m_lawpass.size() )
        createLowPassFilter(fft.size());
    // compute
    cv::mulSpectrums(fft, m_lawpass, fft, cv::DFT_COMPLEX_OUTPUT);
    shiftDFT(&fft);

//    // display spectre
//    ComputeSpectre(fft, &spectre);
//    cv::imshow("spectre after lawpass", spectre);

    // display spectre
//    ShiftDFT(&fft);
//    ComputeSpectre(fft, &spectre);
//    cv::imshow("spectre After lawpass after shift", spectre);

    // compute DFT inverse
    cv::dft(fft, *out, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT|cv::DFT_SCALE);
    out->convertTo(*out, CV_32F, 1/255.);

//    cv::waitKey(0);
}


void Butterworth::createLowPassFilter(const cv::Size &size)
{
    int cc = size.width / 2;
    int cr = size.height / 2;

    cv::Mat im(size, CV_32F);
    for(int i=1; i<im.rows; ++i)
    {
        int ii = i - cr;
        float *ptr = im.ptr<float>(i);
        for(int j=0; j<im.cols; ++j)
        {
            int jj = j - cc;
            float val = sqrt(ii*ii+jj*jj) / m_wc;
            ptr[j] = 1 / ( 1 + pow(val, 2*m_n) );
        }
    }
    std::vector<cv::Mat> im2(2, im);
    cv::merge(im2, m_lawpass);
}
