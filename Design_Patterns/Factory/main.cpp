#include <memory>
#include <tuple>
#include <iostream>

class Object {
public:
	virtual void play() = 0;
	virtual ~Object() = default;
};
class SpecialObject1: public Object {
public:
	friend class ObjectFactory;
	void play() override {std::cout << "SpecialObject1().play()" << std::endl;}
private:
	SpecialObject1() = default;
};
class SpecialObject2: public Object {
public:
	friend class ObjectFactory;
	void play() override {std::cout << "SpecialObject2().play()" << std::endl;}
private:
	SpecialObject2() = default;
};

class ObjectFactory{
public:
	static std::unique_ptr<Object> create(int config) {
		
		switch(config){
			case 1:
				return std::unique_ptr<Object>(new SpecialObject1());
				
			case 2:
				[[fallthrough]]
			default:
				return std::unique_ptr<Object>(new SpecialObject2());
		}
		return std::unique_ptr<Object>(new SpecialObject1());
	}
};

int main(int argc, char** argv)
{
	std::ignore = argc;
	std::ignore = argv;
	
	auto spec_obj_created_using_factory = ObjectFactory::create(2);
	
	spec_obj_created_using_factory->play();

	return 0;
}