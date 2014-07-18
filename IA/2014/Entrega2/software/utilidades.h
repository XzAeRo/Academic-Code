#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>
#include "array2d.h"

using namespace std;
using std::vector;

class Utilidades
{
public:
    Utilidades();
    void print_usage();
    vector<int> get_instance(int instance);
    vector< vector<int> > get_boats();
    void print_solution_to_file(Array2D solution, int n, int T, int id);
    void print_to_screen(Array2D solution, int n, int T);
};

#endif // UTILIDADES_H
