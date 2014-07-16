#ifndef ARRAY3D_H
#define ARRAY3D_H
#include<vector>

using namespace std;

class Array3D
{
    int m_width, m_height;
    vector<int> m_data;
public:
    Array3D(int x, int y, int z, int init);
    int& operator()(int x, int y, int z);
};

#endif // ARRAY3D_H
