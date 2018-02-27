#include "PizzaSeparator.h"
#include "PrintVector.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Point.h"
#include "Parser.h"

using namespace std;

PizzaSeparator::PizzaSeparator(std::vector<std::vector<bool>>* v){
	for(unsigned int i = 0; i < columns; ++i){
		isTaken.emplace_back();
		for(unsigned int j = 0; j < rows; ++j){
			isTaken[i].push_back(false);
		}
	}
	toSlice=v;
}

void PizzaSeparator::SlicePizza(){
	int counter=0;

	while((startingP=FindStartingPoint()).IsValid()){

		/*endP=startingP;
		if((*toSlice)[startingP.GetX()][startingP.GetY()]==0)actTom++;
		else actMus++;

		while((actTom<::min or actMus<::min) or FieldSize()<=::max){
			if(!ExpandVertically()){
				if(!ExpandHorizontally()){
					if(FieldSize()<::max){
						isTaken[startingP.GetX()][startingP.GetY()]=true;
						break;		
					}
				}
			}else if(FieldSize()>=::max){
				if(!ExpandHorizontally()){
					isTaken[startingP.GetX()][startingP.GetY()]=true;
					break;
				}
				while(FieldSize()>=::max){
					DecreaseVertically();
				}if(FieldSize()<1){
					isTaken[startingP.GetX()][startingP.GetY()]=true;
					break;
				}
			}
		}
		if(actMus!=0 and actTom!=0 and endP.IsValid() and startingP.IsValid()){
			SetTaken();
			AddToResults();
		}
		actMus=0;
		actTom=0;*/

		endP=startingP;
		if((*toSlice)[startingP.GetX()][startingP.GetY()])actMus++;
		else actTom++;

		while(actTom<::min or actMus<::min or FieldSize()>::max){ //dopoki field size za duzy lub nie mamy odpowiedniej ilosci skladnikow cos robimy
			if(ExpandVertically());
			else if(!ExpandHorizontally()){
				if(FieldSize()<::max){
					isTaken[startingP.GetX()][startingP.GetY()]=true;
					break;
				}
			}
			if(FieldSize()>=::max){
				if(!ExpandHorizontally()){
					isTaken[startingP.GetX()][startingP.GetY()]=true;
					break;
				}
			}
			while(FieldSize()>=::max)DecreaseVertically();
			if(FieldSize()<=1){
				isTaken[startingP.GetX()][startingP.GetY()]=true;
				break;
			}
		}

		if(actMus>=::min and actTom>=::min and endP.IsValid() and startingP.IsValid() and FieldSize()<=::max){
			SetTaken();
			AddToResults();
			counter++;
		}
		if(counter%500==0)cout<<counter<<endl;
		actMus=0;
		actTom=0;
	}
}

PizzaSeparator::~PizzaSeparator(){
	delete toSlice;
}

Point PizzaSeparator::FindStartingPoint(){
	for(unsigned int i = 0; i < columns; ++i){
		for(unsigned int j = 0 ; j < rows; ++j){
			if(isTaken[i][j]==0) return Point(i, j, validity::valid);
		}
	}
	return Point(0,0,validity::notvalid);
}

bool PizzaSeparator::IsValid(const Point& upperLeft, const Point& lowerRight)
{
	if(lowerRight.GetX()>=columns or lowerRight.GetY()>=rows)return false;
	for (unsigned int i=upperLeft.GetX(); i<=lowerRight.GetX(); ++i)
	{
		for (unsigned int j=upperLeft.GetY(); j<=lowerRight.GetY(); ++j)
		{
			if (isTaken[i][j]==true)
				return false;
		}
	}
	return true;
}

unsigned int PizzaSeparator::FieldSize(){
	return (endP.GetX()-startingP.GetX()+1)*(endP.GetY()-startingP.GetY()+1);
}

bool PizzaSeparator::ExpandVertically(){
	if((IsValid( Point(startingP.GetX(),endP.GetY()) , Point(endP.GetX() , endP.GetY() + 1) ) ) and  endP.GetY() + 1 < rows){
		endP.SetY( endP.GetY() + 1);
		for(unsigned int i = startingP.GetX(); i <= endP.GetX(); ++i){
			if((*toSlice)[i][endP.GetY()]==0)actTom++;
			else actMus++;
		}
		return true;
	}
	return false;
}

bool PizzaSeparator::ExpandHorizontally(){
	if((IsValid(Point(endP.GetX(),startingP.GetY() ) , Point(endP.GetX() +1 , endP.GetY() ) ) )and  endP.GetX() + 1 < columns){
		endP.SetX( endP.GetX() + 1);
		for(unsigned int j = startingP.GetY(); j <= endP.GetY(); ++j){
			if((*toSlice)[endP.GetX()][j]==0)actTom++;
			else actMus++;
		}
		return true;
	}
	return false;
}

void PizzaSeparator::SetTaken(){
	for(unsigned int i = startingP.GetX(); i<=endP.GetX() ; ++i){
		for(unsigned int j = startingP.GetY(); j<=endP.GetY(); ++j){
			isTaken[i][j]=1;
		}
	}
}

void PizzaSeparator::DecreaseVertically(){
	for(unsigned int i = startingP.GetX(); i <= endP.GetX(); ++i){
		if((*toSlice)[i][endP.GetY()]==0)actTom--; ///HERE !!!!! TU BYLO if((*toSlice)[endP.GetY()][i]==0)actTom--;
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
	std::ofstream outputFile("big.out");;
	if (!outputFile.is_open())
	{
		std::cout<<"Could not open a file"<<std::endl;
		exit(-1);
	}
	outputFile<<m_result.size()<<std::endl;
	for (std::vector<std::pair<Point, Point>>::iterator i = m_result.begin(); i!=m_result.end(); ++i)
	{
		outputFile<<(*i).first.GetY()<<" ";
		outputFile<<(*i).first.GetX()<<" ";
		outputFile<<(*i).second.GetY()<<" ";
		outputFile<<(*i).second.GetX()<<std::endl;
	}

}
