#include <iostream>
#include "userclass.hpp"

int main(int argc, char** argv) {
	Userclass instance("test CMake");
	std::cout << instance.get_x() << std::endl;
	return 0;
}