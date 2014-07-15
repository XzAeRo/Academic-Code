#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "main.h"

using namespace std;


int main(int argc, char **argv)
{
    cout << "================================================================= \n"
            "Entrega 2 - Inteligencia Artificial 2014-1\n"
            "'Progressive Party Problem' - Implementacion en Backtracking + GBJ\n"
            "Autor: Victor Gonzalez (victor.gonzalezro@alumnos.usm.cl)\n"
            "Codigo Fuente y Material extra en https://github.com/XzAeRo/Academic-Code/tree/master/IA/2014/\n"
            "================================================================= \n\n";

    Utilidades utils;
    int n_instancia = 1;

    /****************************************************************/
    /******* Obtencion de datos y acciones previas al problema ******/
    /****************************************************************/

    // Si el usuario no define la instancia por parametros, se le pregunta directamente.
    if (argc == 1)
    {
        cout << "Por favor ingrese el numero de la instancia que desea utilizar: ";
        cin >> n_instancia;
    }
    else if (argc == 3 && argv[1] == string("-instancia"))
    {
        n_instancia = atoi(string(argv[2]).c_str());
    }
    else
    {
        cout << "Uso:\t./app \t[-instancia 1..n]" << endl;
        return 1;
    }

    // cargar datos desde los archivos
    vector< vector<int> > botes = utils.get_boats();
    vector<int> instancia = utils.get_instance(n_instancia);

    // verificar si la informacion proporcionada por los archivos coincide
    if (botes.size() != instancia.size())
    {
        cout << "La instancia elegida tiene una cantidad distinta de botes a las definidas por ppp.cap" << endl;
        return 1;
    }


    /****************************************************************/
    /******* Busqueda de solucion mediante Backtracking (GBJ) *******/
    /****************************************************************/
    int T = TMIN;               // intervalos de tiempo
    int n = botes.size();       // cantidad de botes en la fiesta
    Array2D visitas(n,n,0);       // visitas[i][j] = {1..T} la tripulacion j visita el bote i en el instante t
    Array3D mismo_bote(n,n,T,0);    // mismo_bote[i][j][t]: 1 si la tripulacion i y j se encuentran en el mismo bote en el instante t
    Array2D mejor_solucion(n,n,0);


    int i,j,t;

    for (i=0 ; i<n ; i++)
    {
        for (j=0 ; j<n ; j++)
        {
            visitas(i,j) = 1;
        }
    }


    return 0;
}
