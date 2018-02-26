#pragma once

#include "enum.h"

class Point{
public:
	Point(unsigned int x = 0, unsigned int y = 0, validity v = validity::valid):isValid(v),m_x(x),m_y(y){};
	unsigned int GetX() const {return m_x;}
	unsigned int GetY() const {return m_y;}
	bool IsValid();
	void Print();
	void SetX(const unsigned int x);
	void SetY(const unsigned int y);
	validity isValid;
private:
	unsigned int m_x;
	unsigned int m_y;
};
