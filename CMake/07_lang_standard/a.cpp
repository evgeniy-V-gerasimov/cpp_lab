#include "a.hpp"

ModuleA::ModuleA(){ std::cout << "ModuleA" << std::endl;}

void ModuleA::use_cpp17std(){
	std::tuple<int, int> tpl(12, 42);
	auto [x, y] = tpl;
	std::cout << x+y << std::endl;
}