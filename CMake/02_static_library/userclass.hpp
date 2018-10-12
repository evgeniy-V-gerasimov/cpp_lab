#ifndef USERCLASS_HPP
#define USERCLASS_HPP
 
#include <string>

class Userclass{
public:
	Userclass(std::string in);
	std::string get_x() const;
private:
	std::string x;	 
};
 
 
 
#endif //LIB_X_HPP