#include <iostream>
#include <vector>

#include "Main.h"

int main(){
	//Parser();
	PizzaSeparator sep(Parser());
	sep.SlicePizza();
	sep.PrintResults();
	sep.SaveToFile();
}
