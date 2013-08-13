#include <iostream>
#include <vector>
#include <fstream>
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

float solutionCost(matrix solution, vector<Airplane> airplanes, int n_planes, int n_runways){
	float sum = 0.0;
	for (int j = 0; j < n_runways; j++){
		for (int i = 1; i < n_planes; i++){
			int landing_time = solution.getValue(i,j);
			if (landing_time > 0){
				sum += airplanes[i].get_cost(landing_time);
			}
		}
	}
	return sum;
}

bool consistent(matrix solution, vector<Airplane> airplanes, int n_planes, int n_runways){
	for (int j = 0; j < n_runways; j++){
		for (int i = 1; i < n_planes; i++){
			int landing_time_1 = solution.getValue(i-1,j);
			int landing_time_2 = solution.getValue(i,j);
			if (landing_time_2 != 0 && airplanes[i-1].check_collision(landing_time_2, airplanes[i].get_id()))
				return false;
		}
	}
	return true;
}

matrix GBJ(vector<Airplane> airplanes, matrix constraints, matrix ancestors, vector<int> parent, int n_planes, int n_runways){
	matrix solution(n_planes,n_runways);
	matrix best_solution(n_planes,n_runways);
	float min_cost = 99999999999.9;
	int i=0, current, trials = 1000;
	bool empty_domain = false;

	while (i < n_planes && trials > 0){
		int runway_instantation = 0, domain_instantation = airplanes[i].get_min_landing_time();

		solution.setValue(i,runway_instantation,domain_instantation);
		airplanes[i].set_landing_time(domain_instantation);
		airplanes[i].set_runway(runway_instantation);

		while (!consistent(solution,airplanes,n_planes,n_runways) && domain_instantation <= airplanes[i].get_last()){
			runway_instantation = 0;
			while (!consistent(solution,airplanes,n_planes,n_runways) && runway_instantation < n_runways){
				if (runway_instantation > 0){
					//undo latest solution
					solution.setValue(i,runway_instantation - 1,0);
				}
				solution.setValue(i,runway_instantation,domain_instantation);
				airplanes[i].set_landing_time(domain_instantation);
				airplanes[i].set_runway(runway_instantation);

				runway_instantation++;
			}

			if (domain_instantation == airplanes[i].get_last() && i > 0){
				// no consistent
				i = parent[i];	// backjump
			}
			domain_instantation++;
		}

		i++;

	}

	

	return solution;
}


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
	airplanes = sortByBef(populate(filename));

	// create and build GBJ network
	n_planes = airplanes.size();
	matrix ancestors(n_planes,n_planes);		// [binario] ancestros de un nodo del grafo
	matrix constraint(n_planes,n_planes);		// [binario] grafo restricciones
	vector<int> parent(n_planes,0);				// [binario] nodo padre de variables del grafo

	buildConstraintsGraph(constraint, airplanes, n_planes);
	buildAncestorsLists(ancestors, constraint, n_planes);

	for (int i=0; i < n_planes; i++)
		for (int j=0; j < i; j++)
			if (ancestors.getValue(i,j)==1)
				parent[i] = j;

	matrix solution = GBJ(airplanes,constraint,ancestors,parent,n_planes,n_runways);

	for (int l=0; l < n_planes; l++)
		for (int m=0; m < n_runways ; m++)
			cout << airplanes[l].get_id() << " " << solution.getValue(l,m) << endl;

	return 0;
}