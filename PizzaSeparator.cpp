#include "PizzaSeparator.h"
#include "PrintVector.h"

#include <iostream>
#include "Point.h"
#include "Parser.h"

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

	Point startingP(FindStartingPoint());
	if(!startingP.IsValid())return;
	startingP.Print();
}

PizzaSeparator::~PizzaSeparator(){
	delete toSlice;
}

Point PizzaSeparator::FindStartingPoint(){
	for(unsigned int i = 0; i < rows; i++){
		for(unsigned int j = 0 ; j < columns; j++){
			if(isTaken[i][j]==0) return Point(i,j);
		}
	}
	return Point(10000000,1000000);
}

bool PizzaSeparator::IsValid(const Point& upperLeft, const Point& lowerRight)
{
	for (int i=upperLeft.GetX(); i<=lowerRight.GetX(); ++i)
	{
		for (int j=lowerRight.GetY(); j<=upperLeft.GetY(); ++j)
		{
			if (isTaken[i][j]==true)
				return false;
		}
	}

	return true;
}