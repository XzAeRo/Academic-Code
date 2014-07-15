#ifndef ARRAY2D_H
#define ARRAY2D_H

#include<vector>

using namespace std;

class Array2D
{
    int m_width, m_height;
    vector<int> m_data;
public:
    Array2D(int x, int y, int init);
    int& operator()(int x, int y);
};

#endif // ARRAY2D_H
