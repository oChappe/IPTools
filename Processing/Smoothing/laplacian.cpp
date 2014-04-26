#include "laplacian.h"


Laplacian::Laplacian(int rows, int cols)
{
    setSize(rows, cols);
}


void Laplacian::setSize(int rows, int cols)
{
    if( cols == -1 )
        cols = rows;
    if( (m_rows != rows) || (m_cols != cols) )
    {
        m_rows = rows;
        m_cols = cols;
        m_kernel = cv::Mat::ones(m_rows, m_cols, CV_32F) / static_cast<float>(m_rows*m_cols);
    }
}


void Laplacian::applyAlgo(const cv::Mat &in, cv::Mat *out)
{
    cv::filter2D(in, *out, -1, m_kernel);
}
