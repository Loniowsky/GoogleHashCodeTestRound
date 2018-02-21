#include "PizzaSeparator.h"

#include <iostream>
#include "Point.h"

using namespace std;

PizzaSeparator::PizzaSeparator(std::vector<std::vector<bool>>& v){
	for(int i = 0; i < rows; i++){
		isTaken.emplace_back();
		int j=0;
		for(int j = 0; j < columns; j++){
			isTaken[i].push_back(0);
		}
	}
}

void PizzaSeparator::SlicePizza(){
	int actTom=0;
	int actMus=0;


}