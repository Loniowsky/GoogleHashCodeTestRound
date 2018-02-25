#include "Point.h"

#include <iostream>

using namespace std;


bool Point::IsValid(){
	if(isValid==validity::notvalid)return false;
	return true;
}

void Point::Print(){
	cout<<m_x<<" "<<m_y<<endl;
}

void Point::SetX(const unsigned int x){
	m_x = x;
}


void Point::SetY(const unsigned int y){
	m_y = y;
}