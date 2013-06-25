#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Airplane {
	int id, bef, target, last;
	float p_bef, p_last;
	vector<int> sep;
	
	public:
		void set_values(int,int,int,int,float,float);
		void push_sep(int);
		bool verify_time(int);
		float check_cost(int);
		int get_id() {return id;}
		int get_bef() {return bef;}
		int get_target() {return target;}
		int get_last() {return last;}
		float get_p_bef() {return p_bef;}
		float get_p_last() {return p_last;}
		vector<int> get_sep() {return sep;}
};

void Airplane::set_values(int id, int bef, int target, int last, float p_bef, float p_last){
	this->id = id;
	this->bef = bef;
	this->target = target;
	this->last = last;
	this->p_bef = p_bef;
	this->p_last = p_last;
}
void Airplane::push_sep(int value){
	this->sep.push_back(value);
}
bool Airplane::verify_time(int suggested_time){
	if(suggested_time >= this->bef && suggested_time <= this->last)
		return true;
	else
		return false;
}
float Airplane::check_cost(int suggested_time){
	if(!this->verify_time(suggested_time))
		return 99999;
	else if(suggested_time >= this->bef && suggested_time < this->target)
		return (float) (this->target - suggested_time)*this->p_bef;
	else if(suggested_time > this->target && suggested_time <= this->last)
		return (float) (suggested_time - this->target)*this->p_last;
	else
		return 0;

}

/* Structures: Airplane populate function */
vector<Airplane> populate(){
    int plane_count, i,j;
	string line, sp_temp;
	string temp_str[5];
	Airplane temp;
	vector<Airplane> airplanes; // this is the return variable

	/* Get plane count from the first line of the file */
	ifstream input("airland1.txt");
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
		
		cout << "\rLoaded " << i+1 << " of " << plane_count << " airplane data";
		airplanes.push_back(temp);
	}

	cout << endl;
	return airplanes;
}

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

int main() {
	vector<Airplane> airplanes;
	
	airplanes = populate();
	airplanes = sortByTarget(airplanes);


	cout << airplanes.at(0).get_bef() << " " << airplanes.at(0).get_last() << endl;
	cout << airplanes.at(0).verify_time(1000) << endl;
	cout << airplanes.at(0).check_cost(1000) << endl;
	cout << airplanes.at(0).get_id() << endl;
	
	return 0;
}