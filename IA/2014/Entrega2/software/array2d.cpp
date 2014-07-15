#include "array2d.h"

Array2D::Array2D(int x, int y, int init):
    m_width(x), m_height(y), m_data(x*y, init)
{}

int& Array2D::operator()(int x, int y){
    return m_data.at(x + y*m_width);
}
