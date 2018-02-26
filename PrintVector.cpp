#include "PrintVector.h"

#include <iostream>

void PrintVector (std::vector<std::vector<bool>>& printed, unsigned rows, unsigned columns)
{
	for (unsigned i=0; i<rows; ++i)
	{
		for (unsigned j=0; j<columns; j++)
		{
			std::cout<<printed[j][i];
		}
		std::cout<<std::endl;
	}

}