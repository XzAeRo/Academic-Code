#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Airplane {
	int bef, target, last;
	float p_bef, p_last;
	vector<int> sep;
	
	public:
		void set_values(int,int,int,float,float);
		void push_sep(int);
		int get_bef() {return bef;}
		int get_target() {return target;}
		int get_last() {return last;}
		float get_p_bef() {return p_bef;}
		float get_p_last() {return p_last;}
		vector<int> get_sep() {return sep;}
};

void Airplane::set_values(int bef, int target, int last, float p_bef, float p_last){
	this->bef = bef;
	this->target = target;
	this->last = last;
	this->p_bef = p_bef;
	this->p_last = p_last;
}
void Airplane::push_sep(int value){
	this->sep.push_back(value);
}

/* Structures: Airplane populate function */
vector<Airplane> populate(){
    int plane_count, i,j;
	string line, sp_temp;
	string temp_str[5];
	Airplane temp;
	vector<Airplane> airplanes; // this is the return variable

	/* Get plane count from the first line of the file */
	ifstream input("airland13.txt");
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
		temp.set_values(atoi(temp_str[0].c_str()), atoi(temp_str[1].c_str()), atoi(temp_str[2].c_str()), atof(temp_str[3].c_str()), atof(temp_str[4].c_str()));
			
		
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
		
		cout << "\rLoaded " << i+1 << " of " << plane_count << " airplane data";
		airplanes.push_back(temp);
	}

	cout << endl;
	return airplanes;
}

int main() {
	vector<Airplane> airplanes;
	
	airplanes = populate();
	
	return 0;
}

