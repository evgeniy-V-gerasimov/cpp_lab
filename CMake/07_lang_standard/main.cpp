#include <iostream>
#include "a.hpp"
#include "b.hpp"

void frval(int&& x) {
	std::cout << "passed rvalue is: " << x << std::endl;
}

int main(int argc, char** argv)
{
	ModuleA a;
	ModuleB b;
	a.use_cpp17std();
	b.use_cpp17std();
	
	//C++11
	auto ch = 'E';
	int* x_ptr = nullptr;
	frval(256);
	

	return 0;
}