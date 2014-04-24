/*!
 * Base class for all image processing
 * Using the design pattern : strategy with the function ApplyAlgo
 **/

#ifndef PROCESSING_H
#define PROCESSING_H

#include <opencv2/opencv.hpp>

class Processing
{
public:
    Processing();

    /*!
     * \brief Process : main function to apply algorithm
     * \param in : image to treat (do not modify)
     * \param out : result image
     */
    void Process(const cv::Mat &in, cv::Mat *out);

protected:
    /*!
     * \brief ApplyAlgo : function to write in each class with the algorihm
     * \param in : 1 channel only
     * \param out
     */
    virtual void ApplyAlgo(const cv::Mat &in, cv::Mat *out) = 0;
};

#endif // PROCESSING_H
