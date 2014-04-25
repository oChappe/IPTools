#ifndef DFT_ALGO_H
#define DFT_ALGO_H

#include <opencv2/opencv.hpp>


/*!
 * \brief ShiftDFT : rearrange result of dft : move the the zero-frequency to the center of the image
 * \param in : dft image, wich will be modified
 */
void ShiftDFT(cv::Mat *in);


/*!
 * \brief CreateOptimalImageForDFT : create a complex image , with optimal size for dft (image sizes that are multiple by 2,3,5)
 * \param in : input image (1 channel)
 * \param out : output image (2 channels)
 */
void CreateOptimalImageForDFT(const cv::Mat &in, cv::Mat *out);


/*!
 * \brief CreateSpectreImage : compute the spectre of the dft
 * \param in : fft result (2 channels, real part and complex part)
 * \param out : spectre
 */
void ComputeSpectre(const cv::Mat &in, cv::Mat *out);


/*!
 * \brief ComputeSpectre : compute the spectre of the dft
 * \param in : fft result : vector must contain 2 Mat : real part and image part
 * \param out : spectre
 */
void ComputeSpectre(const std::vector<cv::Mat> &in, cv::Mat *out);

#endif // DFT_ALGO_H
