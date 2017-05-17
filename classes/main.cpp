#include <iostream>
#include <iomanip>

struct SA {
	int x {1}; 					// Public member-variable
	SA() {std::cout << "SA constructor called" << std::endl;}
};
struct SB: SA { 				// Public default inheritance for struct, private for class
	~SB() {std::cout << "SB destructor called" << std::endl;} // SB::SB() is implicitly-defined, Ctor SA::SA() called
}; 
class CS{
	int x {11}; 				// private member-variable; if default constructor called x = 11
	static bool statVar;
public:
	CS(int&& var): x(var) {}	// Constructor takes Rvalue to initialize private member-variable x
	CS() = default;				// Explicitly defaulted constructor; will not be implicitly declared, because another constructor exists
	void print() const; 		// Member-function prototype CS::print()
	void modStatic() const;
};
void CS::print() const {		// print() should not make changes to member variables.
	std::cout << x << std::endl;
	std::cout << std::boolalpha << statVar << std::endl;
}
void CS::modStatic() const {	// Const member functions can modify static variables
	statVar? statVar=false: statVar=true;
}
bool CS::statVar = true; 		// Initialisation of static variable; single for every instance of class CS

void print(const SA& arg) {
  std::cout << arg.x << std::endl;
}
int main(int argc, char **argv)
{
	{
		SA obj_A1; 				// This instance gets deleted, when reaches scope end
		obj_A1.x = 14;
		print(obj_A1);
	}

	{
		SB obj_A2;
		print(obj_A2);
		SB obj_A3(obj_A2); // Implicit copy-constructor SA(SA&) is called 
	} 

	{
		CS obj_S1(32);
		obj_S1.modStatic();
		obj_S1.print();
	}
	return 0;
}
