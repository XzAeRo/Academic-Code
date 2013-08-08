#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Exception {
	public:
		const char* msg;
		Exception(const char* arg) : msg(arg){}
};

class matrix { 
	int **p, m, n; 
	public: 
		matrix(int row, int col) { 
			m = row; 
			n = col; 
			p = new int*[m]; 
			for (int i = 0; i < m; ++i){
				p[i] = new int[n];
				for (int j = 0; j < n; ++j)
					p[i][j] = 0;
			}
		}

		matrix& operator+ (const matrix& m1){
			return (*this += m1);
		}

		matrix& operator* (const matrix& m1){
			return (*this *= m1);
		}

		matrix& operator+= (const matrix& rhs){
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					p[i][j] += rhs.p[i][j]; 
				} 
			}      
			return *this;
		}

		matrix& operator*= (const matrix& T){
			if(n == T.m){
				for(int i = 0; i < T.m; ++i){
					for(int k = 0; k < n; ++k){
						p[i][k] *= T.p[k][i];
					}
				}
			}
			return *this;
		}

		matrix& operator= (const matrix& T){
			p = T.p;
			n = T.n;
			m = T.m;

			return *this;
		}

		void setValue(int i, int j, int value){
			p[i][j] = value;
		}

		int getValue(int i, int j){
			return p[i][j];
		}
   
};

class Airplane {
	int id, bef, target, last;
	float p_bef, p_last;
	vector<int> sep;
	
	public:
		// setters
		void set_values(int id, int bef, int target, int last, float p_bef, float p_last){
			this->id = id;
			this->bef = bef;
			this->target = target;
			this->last = last;
			this->p_bef = p_bef;
			this->p_last = p_last;
		}
		void push_sep(int value){
			this->sep.push_back(value);
		}

		// getters
		int get_id() {return id;}
		int get_bef() {return bef;}
		int get_target() {return target;}
		int get_last() {return last;}
		float get_p_bef() {return p_bef;}
		float get_p_last() {return p_last;}
		int get_sep(int i) {return sep[i];}

		// misc functions
		bool verify_time(int suggested_time){
			if(suggested_time >= this->bef && suggested_time <= this->last)
				return true;
			else
				return false;
		}
		float check_cost(int suggested_time){
			if(!this->verify_time(suggested_time))
				return 99999;
			else if(suggested_time >= this->bef && suggested_time < this->target)
				return (float) (this->target - suggested_time)*this->p_bef;
			else if(suggested_time > this->target && suggested_time <= this->last)
				return (float) (suggested_time - this->target)*this->p_last;
			else
				return 0;

		}
};

// fill a vector with the airplane data from a file
vector<Airplane> populate(char* filename){
    int plane_count, i,j;
	string line, sp_temp;
	string temp_str[5];
	Airplane temp;
	vector<Airplane> airplanes; // this is the return variable

	/* Get plane count from the first line of the file */
	ifstream input(filename);
	getline(input, line);
	plane_count = atoi(line.c_str());
	
	/* Safely populate a list of Airplanes */
	for(i=0 ; i < plane_count ; i++){
		
		/* Get airplane i data */
		getline(input, line);
    	stringstream ap(line);
    	// the following 'while' splits a string separated by spaces into a fixed array
    	j = 0;
		while (ap.good() && j < 5){
			ap >> temp_str[j];
			++j;
		}
		// populate temp airplane data
		temp.set_values(i, atoi(temp_str[0].c_str()), atoi(temp_str[1].c_str()), atoi(temp_str[2].c_str()), atof(temp_str[3].c_str()), atof(temp_str[4].c_str()));
			
		
		/* Get airplane separation time for airplane i */
		getline(input, line);
    	stringstream sp(line);
    	// the following 'while' splits a string separated by spaces into a fixed array
    	j = 0;
		while (sp.good() && j < plane_count){
			sp >> sp_temp;
			temp.push_sep(atoi(sp_temp.c_str()));
			++j;
		}
		
		airplanes.push_back(temp);
		cout << "\rLoading airplanes data from file... " << (((i+1)*100)/plane_count) << "%";
	}

	cout << endl;
	return airplanes;
}

// sorting functions
vector<Airplane> sortByTarget(vector<Airplane> airplanes){
	Airplane airplane;
	for(int i=0 ; i<airplanes.size() ; i++){
		for(int j=0 ; j<i ; j++){
			if(airplanes.at(i).get_target() < airplanes.at(j).get_target()){
				swap(airplanes.at(i), airplanes.at(j));
			}
		}
	}
	return airplanes;
}
vector<Airplane> sortByBef(vector<Airplane> airplanes){
	Airplane airplane;
	for(int i=0 ; i<airplanes.size() ; i++){
		for(int j=0 ; j<i ; j++){
			if(airplanes.at(i).get_bef() < airplanes.at(j).get_bef()){
				swap(airplanes.at(i), airplanes.at(j));
			}
		}
	}
	return airplanes;
}
vector<Airplane> sortByLast(vector<Airplane> airplanes){
	Airplane airplane;
	for(int i=0 ; i<airplanes.size() ; i++){
		for(int j=0 ; j<i ; j++){
			if(airplanes.at(i).get_last() < airplanes.at(j).get_last()){
				swap(airplanes.at(i), airplanes.at(j));
			}
		}
	}
	return airplanes;
}

// checker functions
bool checkPossibleCollision(Airplane a, Airplane b){
	if(a.get_last() + a.get_sep(b.get_id()) >= b.get_bef() && b.get_last() >= a.get_bef())
		return true;
	return false;
}




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
		cout << "Usage: ALSP_GBJ -file airlandXX.txt -n_runways N" << endl;
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