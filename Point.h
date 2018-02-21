#pragma once

class Point{
public:
	Point(unsigned int x = 0, unsigned int y = 0):m_x(x),m_y(y){};
	unsigned GetX() const {return m_x;}
	unsigned GetY() const {return m_y;}
	
private:
	unsigned m_x;
	unsigned m_y;
};
