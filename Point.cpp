#include "Point.h"

#include <iostream>

using namespace std;

bool Point::IsValid(){
	if(m_x==1000000&&m_y==1000000)return false;
	else return true;
}

void Point::Print(){
	cout<<m_x<<" "<<m_y<<endl;
}