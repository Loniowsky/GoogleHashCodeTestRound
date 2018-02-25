#pragma once

#include <vector>
#include <utility>
#include "Point.h"
#include "enum.h"

class PizzaSeparator{
	public:
		PizzaSeparator(std::vector<std::vector<bool>>* v);
		~PizzaSeparator();
		void SlicePizza();
		void PrintResults();
		void SaveToFile();


	private:
		Point FindStartingPoint();
		unsigned int FieldSize();
		bool IsValid(const Point& upperLeft, const Point& lowerRight);
		bool ExpandVertically();
		bool ExpandHorizontally();
		void  DecreaseVertically();
		void SetTaken();
		void AddToResults();
		std::vector<std::pair<Point, Point>> m_result;
		std::vector<std::vector<bool>> isTaken;
		std::vector<std::vector<bool>>* toSlice;
		Point startingP;
		Point endP;
		int actTom=0;
		int actMus=0;
};