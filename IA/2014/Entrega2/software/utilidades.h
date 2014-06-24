#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>

using namespace std;
using std::vector;

class Utilidades
{
public:
    Utilidades();
    void print_usage();
    vector<int> get_instance(int instance);
    vector< vector<int> > get_boats();
};

#endif // UTILIDADES_H
