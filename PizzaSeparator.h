#pragma once

#include <vector>
#include "Point.h"
#include "enum.h"

class PizzaSeparator{
	public:
		PizzaSeparator(std::vector<std::vector<bool>>* v);
		~PizzaSeparator();
		void SlicePizza();

	private:
		Point FindStartingPoint();
		unsigned int FieldSize(Point start, Point end);
		bool IsValid(const Point& upperLeft, const Point& lowerRight);
		bool ExpandVertically();
		bool ExpandHorizontally();
		void  DecreaseVertically();
		void SetTaken(Point start, Point end);
		std::vector<Point> m_result;
		std::vector<std::vector<bool>> isTaken;
		std::vector<std::vector<bool>>* toSlice;
		Point startingP;
		Point endP;
		int actTom=0;
		int actMus=0;
};