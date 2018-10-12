#include "userclass.hpp"
	 
Userclass::Userclass(std::string in) : x(in) 
{}
std::string Userclass::get_x() const {
	return x;
}