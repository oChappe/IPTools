#ifndef BUTTERWORTH_H
#define BUTTERWORTH_H

#include "smoothing.h"

class Butterworth : public Smoothing
{
public:
    Butterworth(float wc=20, float n=2);

    void SetWc(float val);
    void SetN(float val);

    float GetWc() const;
    float GetN() const;

protected:
    virtual void ApplyAlgo(const cv::Mat &in, cv::Mat *out);

private:
    /*!
     * \brief CreateLowPass : create the loaw pass filter to apply algorithme (called if new and previous images have different size)
     */
    void CreateLowPassFilter(const cv::Size &size);

    //! filter matrix to apply to the fft image
    cv::Mat lawpass;

    //! cutoff frequency
    float m_wc;

    //! order
    float m_n;
};


inline void Butterworth::SetWc(float val) {m_wc=val;}
inline void Butterworth::SetN(float val) {m_n=val;}

inline float Butterworth::GetWc() const {return m_wc;}
inline float Butterworth::GetN() const {return m_n;}


#endif // BUTTERWORTH_H
