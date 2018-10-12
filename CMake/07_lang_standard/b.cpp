#include "b.hpp"

ModuleB::ModuleB(){ std::cout << "ModuleB" << std::endl;}

void ModuleB::use_cpp17std(){
	if(int x{42}; x == 42) {
		std::cout << "if init feature" << std::endl;
	}
}