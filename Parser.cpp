#include "Parser.h"
#include "PrintVector.h"

unsigned rows = 0;
unsigned columns = 0;

unsigned min = 0;
unsigned max = 0;



#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

std::vector<std::vector<bool>>* Parser ()
{
	std::ifstream inputFile ("big.in");
	if (!inputFile.is_open())
	{
		std::cerr<<"Could not open file. Exiting"<<std::endl;
		exit(-1);
	}
	
	std::string line;

	getline (inputFile, line);

	rows = atoi(line.c_str());
	line = line.substr(line.find(" ", 1));
	columns = atoi(line.c_str());
	line = line.substr(line.find(" ", 1));
	min = atoi(line.c_str());
	line = line.substr(line.find(" ", 1));
	max = atoi(line.c_str());

	std::cout<<"Rows: "<<rows<<std::endl;
	std::cout<<"Columns: "<<columns<<std::endl;
	std::cout<<"Min: "<<min<<std::endl;
	std::cout<<"Max: "<<max<<std::endl;

	std::string pizzaRow;
	auto ptrToVector = new std::vector<std::vector<bool>>;
	char ingredient;


	for (unsigned i=0; i<columns; ++i)
	{
		ptrToVector->emplace_back();
	}

	for (unsigned i=0; i<rows; ++i)
	{
		getline (inputFile, pizzaRow);
		for (unsigned j=0; j<columns; ++j)
		{
			ingredient = pizzaRow.at(0);
			pizzaRow.erase(0,1);
			//std::cout<<ingredient;
			if (ingredient=='T')
				ptrToVector->at(j).push_back(false);
			else
				ptrToVector->at(j).push_back(true);

		}
		//std::cout<<std::endl;
	}

	//PrintVector(*ptrToVector, rows, columns);

	return ptrToVector;
	

}