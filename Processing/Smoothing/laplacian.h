#ifndef LAPLACIAN_H
#define LAPLACIAN_H

#include "smoothing.h"


class Laplacian : public Smoothing
{
public:
    /*!
     * \brief Laplacian : construct the kernel of the filter
     * \param rows : nb rows of the kernel
     * \param cols : nb cols of the kernel, if -1 : square matrix rows*rows
     */
    Laplacian(int rows = 10, int cols = -1);

    /*!
     * \brief setSize : update size of the kernel
     * \param rows : nb rows of the kernel
     * \param cols : nb cols of the kernel, if -1 : square matrix rows*rows
     */
    void setSize(int rows, int cols = -1);

    int getRows() const;
    int getCols() const;

protected:
    virtual void applyAlgo(const cv::Mat &in, cv::Mat *out);

private:
    //! filter for images
    cv::Mat m_kernel;

    //! nb rows of the kernel
    int m_rows;

    //! nb columns of the kernel
    int m_cols;
};


inline int Laplacian::getRows() const {return m_rows;}
inline int Laplacian::getCols() const {return m_cols;}


#endif // LAPLACIAN_H
