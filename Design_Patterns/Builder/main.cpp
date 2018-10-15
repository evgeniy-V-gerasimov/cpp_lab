#include <memory>
#include <tuple>
#include <iostream>
#include <string_view>

class Object {
public:
	class Builder {
	public:
		Builder()				{std::cout << "ctor: Builder" <<std::endl;}
		~Builder()				{std::cout << "dtor: Builder" <<std::endl;}
		std::string prop1 = "def1";
		std::string prop2 = "def2";
		std::string prop3 = "def3";
		Object::Builder& setProp1(std::string_view p) {prop1 = p; return *this;}
		Object::Builder& setProp2(std::string_view p) {prop2 = p; return *this;}
		Object::Builder& setProp3(std::string_view p) {prop3 = p; return *this;}
		Object build() {return Object(*this);}
	};
	void list_properties() {
		std::cout 	<< "Object properties:\n"	<< property1 << '\n' 
												<< property2 << '\n'
												<< property3 << std::endl;
	}
private:
	explicit Object(Object::Builder& builder) 
		: property1(builder.prop1)
		, property2(builder.prop2)
		, property3(builder.prop3)
	{}
	std::string property1;
	std::string property2;
	std::string property3;
};

int main(int argc, char** argv)
{
	std::ignore = argc;
	std::ignore = argv;
	
	auto object1 = std::make_unique<Object::Builder>()->setProp1("red")
														.setProp2("green")
														.setProp3("blue")
														.build();
	object1.list_properties();
	
	auto object2 = std::make_unique<Object::Builder>()->setProp3("blue").build();
	object2.list_properties();
	return 0;
}