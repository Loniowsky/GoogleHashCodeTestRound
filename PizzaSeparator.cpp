#include "PizzaSeparator.h"

#include <iostream>
#include "Point.h"

using namespace std;

PizzaSeparator::PizzaSeparator(std::vector<std::vector<bool>>* v){
	for(unsigned int i = 0; i < rows; i++){
		isTaken.emplace_back();
		for(unsigned int j = 0; j < columns; j++){
			isTaken[i].push_back(0);
		}
	}
	toSlice=v;
}

void PizzaSeparator::SlicePizza(){
	int actTom=0;
	int actMus=0;

	
}

PizzaSeparator::~PizzaSeparator(){
	delete toSlice;
}