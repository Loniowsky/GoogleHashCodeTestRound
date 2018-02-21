#include <iostream>
#include <vector>

#include "Main.h"

int rows = 2;
int columns = 2;

int main(){
	std::vector<std::vector<bool>> v;
	v.emplace_back();
	v.emplace_back();
	v[0].emplace_back(0);
	v[0].emplace_back(1);
	v[1].emplace_back(1);
	v[1].emplace_back(0);


	PizzaSeparator sep(v);
}