#include<iostream>
#include <vector>
#include "airplane.h"
using namespace std;

int main() {
	vector<Airplane> airplanes;
	Airplane airplane;
	
	airplanes = populate();
	
	return 0;
}
