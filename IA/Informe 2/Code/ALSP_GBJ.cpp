#include <iostream>
#include <vector>
#include "matrix.cpp"
#include "airplane.cpp"
using namespace std;


/*****************************************************************************************/
/******************** GBJ Implementation *************************************************/
/*****************************************************************************************/

void buildConstraintsGraph(matrix constraint, vector<Airplane> airplanes, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			// check if in any landing window of i is within the landing window of j
			// if true then add the reference as a constraint
			if(checkPossibleCollision(airplanes[i],airplanes[j]) && i != j)
				constraint.setValue(i,j,1);
		}
		cout << "\rBuilding constraints graph... " << (((i+1)*100)/size) << "%";
	}
	cout << endl;
}

void buildAncestorsLists(matrix ancestors, matrix constraint, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < i; j++){
			if (constraint.getValue(i,j) == 1){
				ancestors.setValue(i,j,1);
			}
		}
		cout << "\rBuilding ancestors lists... " << (((i+1)*100)/size) << "%";
	}
	cout << endl;
}

//vector<int> GBJ(vector<Airplane> airplanes){

//	return NULL;
//}


int main(int argc, char* argv[]) {
	int n_runways, n_planes;
	vector<Airplane> airplanes;
	char* filename;

	// process input data
	if (argc < 5) {
		cout << "Usage: ALSP_GBJ -file airlandXX.txt -n_runways N" << endl << endl;;
		return 0;
	} else {
		filename = argv[2];
		n_runways = atoi(argv[4]);
	}
	airplanes = sortByTarget(populate(filename));

	// create and build GBJ network
	n_planes = airplanes.size();
	matrix ancestors(n_planes,n_planes);		// [binario] ancestros de un nodo del grafo
	matrix constraint(n_planes,n_planes);		// [binario] grafo restricciones
	vector<int> parent(n_planes,0);				// [binario] nodo padre de variables del grafo

	buildConstraintsGraph(constraint, airplanes, n_planes);
	buildAncestorsLists(ancestors, constraint, n_planes);


	return 0;
}