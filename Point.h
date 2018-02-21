#pragma once

class Point{
public:
	Point(unsigned int x = 0, unsigned int y = 0):m_x(x),m_y(y){};
	int GetX() const {return m_x;}
	int GetY() const {return m_y;}
	bool IsValid();
	void Print();
private:
	unsigned int m_x;
	unsigned int m_y;
};
