#include <iostream>
#include <memory>

#include "pimpl_cheshire_cat_widget.hpp"


int main(int argc, char** argv) {

	auto widget = std::make_unique<Widget>();
	std::cout << widget->sum() << '\n';

	return 0;
} 