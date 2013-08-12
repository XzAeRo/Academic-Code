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
		for (int i = 0; i < n_planes; i++){
			int landing_time_1 = solution.getValue(i,j);
			for (int k=0; k < n_planes; k++){
				int landing_time_2 = solution.getValue(k,j);
				
				if (landing_time_1 != 0 && landing_time_2 != 0 && airplanes[i].check_collision(landing_time_2, airplanes[k].get_id()) && airplanes[k].check_collision(landing_time_1, airplanes[i].get_id()))
					return false;
			}
		}
	}
	return true;
}

int selectValue(matrix solution, vector<Airplane> airplanes, int n_planes, int n_runways, int plane_instantation){
	for(int runway_instantation = 0; runway_instantation < n_runways; runway_instantation++){
		int domain_instantation = airplanes[plane_instantation].get_best_landing_time();
		airplanes[plane_instantation].set_landing_time(domain_instantation);
		while(domain_instantation > 0){
			solution.setValue(plane_instantation,runway_instantation,domain_instantation);
			if (consistent(solution,airplanes,n_planes,n_runways)){
				airplanes[plane_instantation].reset_domain();
				return domain_instantation;
			}
			domain_instantation = airplanes[plane_instantation].get_best_landing_time();
		}
		airplanes[plane_instantation].reset_domain();
	}
	return -1;
}

int _selectValue(matrix solution, vector<Airplane> airplanes, int n_planes, int n_runways, int plane_instantation){
	for (int i = airplanes[plane_instantation].get_bef(); i <= airplanes[plane_instantation].get_last(); i++){
		for (int j=0; j < n_runways; j++){
			int hattrick = airplanes[plane_instantation].get_best_landing_time();
			solution.setValue(plane_instantation,j,hattrick);
			if (consistent(solution,airplanes,n_planes,n_runways)){
				airplanes[plane_instantation].set_landing_time(hattrick);
				return 0;
			}
		}
	}
	return -1;
}

matrix GBJ(vector<Airplane> airplanes, matrix constraints, matrix ancestors, vector<int> parent, int n_planes, int n_runways){
	matrix solution(n_planes,n_runways);
	matrix best_solution(n_planes,n_runways);
	float min_cost = 99999999999.9;
	int i=0;
	
	while (i < n_planes){
		
		int domain_instantation = _selectValue(solution,airplanes,n_planes,n_runways,i);
		
		if (domain_instantation < 0 && i>0){
			i = parent[i];
		}
		else{
			i++;
		}
	}

	for (int l=0; l < n_planes; l++)
		for (int m=0; m < n_runways ; m++)
			cout << airplanes[l].get_id() << " " << solution.getValue(l,m) << endl;

	cout << solutionCost(solution,airplanes,n_planes,n_runways) << endl;
	cout << consistent(solution,airplanes,n_planes,n_runways) << endl;
	return solution;
}


int main(int argc, char* argv[]) {
	int n_runways, n_planes, trials;
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

	for (int i=0; i < n_planes; i++)
		for (int j=0; j < i; j++)
			if (ancestors.getValue(i,j)==1)
				parent[i] = j;

	GBJ(airplanes,constraint,ancestors,parent,n_planes,n_runways);

	return 0;
}