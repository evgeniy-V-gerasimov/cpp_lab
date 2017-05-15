#include <iostream> // std::cout std::cin std::endl
#include <iomanip> // std::boolalpha
#include <functional> // std::function

char getChar(int&);	//forward declaration of function getChar
int addNumber(int copyInput){ 	// pass by value
	return copyInput + 13;
}
double addNumber(double copyInput){	// function overloading
	return copyInput + 13.3;
}
//void f_callback(const int& cvar, char (*f_ptr)(int&) = &getChar) {
void f_callback(const int& cvar, std::function<char(int&)> f_ptr = getChar) {  
	for(int i = 1; i < cvar; i++){
        std::cout << f_ptr(i) << std::endl;
    }
}
void modifyParam(int& param1, int& param2){ 	// pass by Lvalue reference
	param1 = param2 + 8;
	param2 = param1 - 4;
}
bool isValid(int&& param){	// pass by Rvalue reference
	return param>0 && param<=83 ? true: false;
}
char getChar(int& ch) {
	return ch;
}
template<typename T>	// function template
void setToZero(T& param){
	param = 0;
}

int main(int argc, char **argv)
{
	auto input { 0 };
	auto value { 3 };
	void (*const function_ptr)(int&,int&) = &modifyParam;
	std::cin >> input;
	std::cout << "addNumber(input) returns " << addNumber(input) << std::endl;
	std::cout << "addNumber(input) returns " << addNumber(7.6) << std::endl;
	modifyParam(input, value);	
	std::cout << "input = " << input << "  value = " << value << std::endl;
	(*function_ptr)(input, value);
	std::cout << "input = " << input << "  value = " << value << std::endl;
	std::cout <<  std::boolalpha << isValid(addNumber(input)) << std::endl;
	setToZero(value);
	std::cout << "value = " << value << std::endl;
	f_callback(5);
	f_callback(5, [](int& value)->char{std::cout << "lambda";return value;});
	return 0;
}
