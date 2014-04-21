#ifndef BUTTERWORTH_H
#define BUTTERWORTH_H

#include "smoothing.h"

class Butterworth : public Smoothing
{
public:
    Butterworth();

    void Process(cv::Mat in, cv::Mat out);
};

#endif // BUTTERWORTH_H
