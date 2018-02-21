#pragma once

#include <vector>
#include "Point.h"

extern int rows;
extern int columns;

class PizzaSeparator{
public:
	PizzaSeparator(std::vector<std::vector<bool>>& v);
	void SlicePizza();

private:
	std::vector<Point> m_result;
	std::vector<std::vector<bool>> isTaken;
	std::vector<std::vector<bool>> toSlice;
};
