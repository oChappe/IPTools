/*!
 * Base class for all image processing
 * Using the design pattern : strategy with the function Process
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
    virtual void Process(cv::Mat in, cv::Mat out) = 0;
};

#endif // PROCESSING_H
