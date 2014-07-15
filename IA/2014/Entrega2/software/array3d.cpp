#include "array3d.h"

Array3D::Array3D(int x, int y, int z, int init):
    m_width(x), m_height(y), m_data(x*y*z, init)
{}

int& Array3D::operator()(int x, int y, int z){
    return m_data.at(x + y*m_width + z*m_width*m_height);
}
