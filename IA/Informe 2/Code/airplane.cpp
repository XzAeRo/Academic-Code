#include<iostream>
#include <iomanip>
#include<vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Airplane{
	int bef;
	int target;
	int last;
	float p_bef;
	float p_last;
	vector<int> sep;
};

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
		temp.bef = atoi(temp_str[0].c_str());
		temp.target = atoi(temp_str[1].c_str());
		temp.last = atoi(temp_str[2].c_str());
		temp.p_bef = atof(temp_str[3].c_str());
		temp.p_last = atof(temp_str[4].c_str());
			
		
		/* Get airplane separation time for airplane i */
		getline(input, line);
    	stringstream sp(line);
    	// the following 'while' splits a string separated by spaces into a fixed array
    	j = 0;
		while (sp.good() && j < plane_count){
			sp >> sp_temp;
			temp.sep.push_back(atoi(sp_temp.c_str()));
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
	Airplane airplane;
	
	airplanes = populate();
	
	return 0;
}
