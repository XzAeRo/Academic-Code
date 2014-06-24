#include "utilidades.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using std::vector;

// constructor
Utilidades::Utilidades()
{

}

void Utilidades::print_usage()
{
    cout << "test" << endl;
}

vector<int> Utilidades::get_instance(int instancia)
{
    vector<int> output;
    ifstream file;
    int barco;

    ostringstream t_filename;
    t_filename << "ppp_data/ppp_" << instancia << ".hst";
    string filename = t_filename.str();

    file.open(filename.c_str());

    if (file.is_open())
    {
        cout << "Cargando instancia " << instancia << "... ";

        while ( file >> barco)
        {
            output.push_back(barco);
        }

        file.close();
        cout << "Listo!" << endl;
    }

    return output;
}


vector< vector<int> > Utilidades::get_boats()
{
    vector< vector<int> > output;
    ifstream file;
    int capacidad, tripulacion;

    file.open("ppp_data/ppp.cap");

    if (file.is_open())
    {
        cout << "Cargando datos de los botes... ";

        while ( file >> capacidad >> tripulacion)
        {
            vector<int> row;
            row.push_back(capacidad);
            row.push_back(tripulacion);
            output.push_back(row);
        }

        file.close();
        cout << "Listo!" << endl;
    }
    return output;
}
