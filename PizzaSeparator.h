#pragma once

#include <vector>
#include "Point.h"

class PizzaSeparator{
	public:
		PizzaSeparator(std::vector<std::vector<bool>>* v);
		~PizzaSeparator();
		void SlicePizza();
		Point FindStartingPoint();

		bool IsValid(const Point& upperLeft, const Point& lowerRight);

	private:
		std::vector<Point> m_result;
		std::vector<std::vector<bool>> isTaken;
		std::vector<std::vector<bool>>* toSlice;
};
