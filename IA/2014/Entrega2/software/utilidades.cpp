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
            output.push_back((int) barco);
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

void Utilidades::print_solution_to_file(Array2D solution, int n, int id)
{
    if (id < 100){
        ofstream file;
        ostringstream t_filename;
        t_filename << "solutions/" << id << ".sol";
        string filename = t_filename.str();

        file.open(filename.c_str());

        if (file.is_open())
        {
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    file << solution(i,j) << " ";
                }
                file << endl;
            }
        }

        file.close();
    }
}

