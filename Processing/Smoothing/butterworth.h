#ifndef BUTTERWORTH_H
#define BUTTERWORTH_H

#include "smoothing.h"

class Butterworth : public Smoothing
{
public:
    Butterworth(float wc=20, float n=2);

    void setWc(float val);
    void setN(float val);

    float getWc() const;
    float getN() const;

protected:
    virtual void applyAlgo(const cv::Mat &in, cv::Mat *out);

private:
    /*!
     * \brief CreateLowPass : create the loaw pass filter to apply algorithme (called if new and previous images have different size)
     */
    void createLowPassFilter(const cv::Size &size);

    //! filter matrix to apply to the fft image
    cv::Mat lawpass;

    //! cutoff frequency
    float m_wc;

    //! order
    float m_n;
};


inline void Butterworth::setWc(float val) {m_wc=val;}
inline void Butterworth::setN(float val) {m_n=val;}

inline float Butterworth::getWc() const {return m_wc;}
inline float Butterworth::getN() const {return m_n;}


#endif // BUTTERWORTH_H
