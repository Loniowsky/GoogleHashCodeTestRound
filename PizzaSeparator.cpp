#include "PizzaSeparator.h"
#include "PrintVector.h"

#include <iostream>
#include <fstream>
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
					if(FieldSize()<::max){
						isTaken[startingP.GetY()][startingP.GetX()]=true;
						break;		
					}
				}
			}if(FieldSize()>=::max){
				if(!ExpandHorizontally()){
					isTaken[startingP.GetY()][startingP.GetX()]=true;
					break;
				}
				while(FieldSize()>=::max){
					DecreaseVertically();
				}if(FieldSize()<1){
					isTaken[startingP.GetY()][startingP.GetX()]=true;
					break;
				}
			}
		}
		if(actMus!=0 and actTom!=0 and endP.IsValid() and startingP.IsValid()){
			SetTaken();
			AddToResults();
		}
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
	if(lowerRight.GetX()>=rows or lowerRight.GetY()>=columns)return false;
	for (unsigned int i=upperLeft.GetX(); i<=lowerRight.GetX(); ++i)
	{
		for (unsigned int j=lowerRight.GetY(); j<=upperLeft.GetY(); ++j)
		{
			if (isTaken[j][i]==true)
				return false;
		}
	}
	return true;
}

unsigned int PizzaSeparator::FieldSize(){
	return (endP.GetX()-startingP.GetX()+1)*(endP.GetY()-startingP.GetY()+1);
}

bool PizzaSeparator::ExpandVertically(){
	if(IsValid( Point(startingP.GetX(),endP.GetY()) , Point(endP.GetX() , endP.GetY() + 1) ) and  endP.GetY() + 1 < rows){
		endP.SetY( endP.GetY() + 1);
		for(unsigned int i = startingP.GetX(); i <= endP.GetX(); ++i){
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
		for(unsigned int i = startingP.GetY(); i <= endP.GetY(); ++i){
			if((*toSlice)[i][endP.GetX()]==0)actTom++;
			else actMus++;
		}
		return true;
	}
	return false;
}

void PizzaSeparator::SetTaken(){
	for(unsigned int i = startingP.GetX(); i<=endP.GetX() ; i++){
		for(unsigned int j = startingP.GetY(); j<=endP.GetY(); j++){
			isTaken[j][i]=1;
		}
	}
}

void PizzaSeparator::DecreaseVertically(){
	for(unsigned int i = startingP.GetX(); i <= endP.GetX(); ++i){
		if((*toSlice)[endP.GetY()][i]==0)actTom--;
		else actMus--;
	}
	endP.SetY( endP.GetY() - 1);
}

void PizzaSeparator::AddToResults()
{
	auto added = std::make_pair(startingP, endP);
	m_result.push_back(added);
}

void PizzaSeparator::PrintResults() 
{
	for (std::vector<std::pair<Point, Point>>::iterator i = m_result.begin(); i!=m_result.end(); ++i)
	{
		std::cout<<(*i).first.GetY()<<" ";
		std::cout<<(*i).first.GetX()<<" ";
		std::cout<<(*i).second.GetY()<<" ";
		std::cout<<(*i).second.GetX()<<std::endl;
	}
}

void PizzaSeparator::SaveToFile()
{
	std::ofstream outputFile;
	outputFile.open("medium.out");
	if (!outputFile.is_open())
		std::cout<<"Could not open a file"<<std::endl;
	outputFile<<m_result.size()<<std::endl;
	for (std::vector<std::pair<Point, Point>>::iterator i = m_result.begin(); i!=m_result.end(); ++i)
	{
		outputFile<<(*i).first.GetY()<<" ";
		outputFile<<(*i).first.GetX()<<" ";
		outputFile<<(*i).second.GetY()<<" ";
		outputFile<<(*i).second.GetX()<<std::endl;
	}

}
