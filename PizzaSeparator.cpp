#include "PizzaSeparator.h"
#include "PrintVector.h"

#include <iostream>
#include "Point.h"
#include "Parser.h"

using namespace std;

PizzaSeparator::PizzaSeparator(std::vector<std::vector<bool>>* v){
	for(unsigned int i = 0; i < rows; ++i){
		isTaken.emplace_back();
		for(unsigned int j = 0; j < columns; ++j){
			isTaken[i].push_back(0);
		}
	}
	toSlice=v;
}

void PizzaSeparator::SlicePizza(){


	while((startingP=FindStartingPoint()).IsValid()){

		endP=startingP;
		if((*toSlice)[startingP.GetY()][startingP.GetX()]==0)actTom++;
		else actMus++;

		while(actTom<::min||actMus<::min){
			if(!ExpandVertically()){
				if(!ExpandHorizontally()){
					if(FieldSize(startingP,endP)<::max){
						isTaken[startingP.GetY()][startingP.GetX()]=true;
						break;		
					}
				}
			}if(FieldSize(startingP,endP)>::max){
				ExpandHorizontally();
				while(FieldSize(startingP,endP)>::max){
					DecreaseVertically();
				}if(FieldSize(startingP,endP)<1){
					isTaken[startingP.GetY()][startingP.GetX()]=true;
					break;
				}
			}
		}
		if(actMus!=0)cout<<actMus<<" "<<actTom<<endl;
		SetTaken(startingP,endP);
		AddToResults (startingP, endP);
		actMus=0;
		actTom=0;
	}
}

PizzaSeparator::~PizzaSeparator(){
	delete toSlice;
}

Point PizzaSeparator::FindStartingPoint(){
	for(unsigned int i = 0; i < rows; ++i){
		for(unsigned int j = 0 ; j < columns; ++j){
			if(isTaken[i][j]==0) return Point(j,i,validity::valid);
		}
	}
	return Point(0,0,validity::notvalid);
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

unsigned int PizzaSeparator::FieldSize(Point start, Point end){
	return (end.GetX()-start.GetX()+1)*(end.GetY()-start.GetY()+1);
}

bool PizzaSeparator::ExpandVertically(){
	if(IsValid( Point(startingP.GetX(),endP.GetY()) , Point(endP.GetX() , endP.GetY() + 1) ) and  endP.GetY() + 1 < rows){
		endP.SetY( endP.GetY() + 1);
		for(int i = startingP.GetX(); i <= endP.GetX(); ++i){
			if((*toSlice)[endP.GetY()][i]==0)actTom++;
			else actMus++;
		}
		return true;
	}
	return false;
}

bool PizzaSeparator::ExpandHorizontally(){
	if(IsValid(Point(endP.GetX(),startingP.GetY() ) , Point(endP.GetX() +1 , endP.GetY() ) ) and  endP.GetX() + 1 < columns){
		endP.SetX( endP.GetX() + 1);
		for(int i = startingP.GetY(); i <= endP.GetY(); ++i){
			if((*toSlice)[i][endP.GetX()]==0)actTom++;
			else actMus++;
		}
		return true;
	}
	return false;
}

void PizzaSeparator::SetTaken(Point start, Point end){
	for(int i = start.GetX(); i<=end.GetX() ; i++){
		for(int j = start.GetY(); j<=end.GetY(); j++){
			isTaken[j][i]=1;
		}
	}
}

void PizzaSeparator::DecreaseVertically(){
	for(int i = startingP.GetY(); i <= endP.GetY(); ++i){
		if((*toSlice)[i][endP.GetX()]==0)actTom--;
		else actMus--;
	}
	endP.SetX( endP.GetX() - 1);
}

void PizzaSeparator::AddToResults(Point& start, Point& end)
{
	auto added = std::make_pair(start, end);
	m_result.push_back(added);
}

void PizzaSeparator::PrintResults() 
{
	for (std::vector<std::pair<Point, Point>>::iterator i = m_result.begin(); i!=m_result.end(); ++i)
	{
		std::cout<<(*i).first.GetX()<<" ";
		std::cout<<(*i).second.GetX()<<" ";
		std::cout<<(*i).first.GetY()<<" ";
		std::cout<<(*i).second.GetY()<<std::endl;

	}
}