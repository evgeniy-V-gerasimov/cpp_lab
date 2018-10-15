#include <memory>
#include <tuple>
#include <iostream>
#include <vector>
#include <list>

class IDynamicIntegerArray {		// Adapter
public:
	virtual void push_back(int) = 0;
	virtual void push_front(int) = 0;
	virtual void print() = 0;
	virtual ~IDynamicIntegerArray() = default;
};

class VectorArray: public IDynamicIntegerArray { // Adaptee 1
public:
	void push_back(int x) override {
		data.push_back(x);
	}
	void push_front(int x) override {
		data.insert(data.begin(), x);
	}
	void print() override {
		for(auto& e : data){
			std::cout << '[' << e << "] ";
		}
		std::cout << std::endl;
	}
private:
	std::vector<int> data;
};

class ListArray: public IDynamicIntegerArray { // Adaptee 2
public:
	void push_back(int x) override {
		data.push_back(x);
	}
	void push_front(int x) override {
		data.push_front(x);
	}
	void print() override {
		for(auto& e : data){
			std::cout << '(' << e << ") ";
		}
		std::cout << std::endl;
	}
private:
	std::list<int> data;
};

int main(int argc, char** argv)
{
	std::ignore = argc;
	std::ignore = argv;
	
	using Container = std::unique_ptr<IDynamicIntegerArray>;
	
	Container box1 {std::make_unique<ListArray>() };
	box1->push_back(42);
	box1->push_back(83);
	box1->push_front(256);
	box1->print();
	
	Container box2 {std::make_unique<VectorArray>() };
	box2->push_back(13);
	box2->push_front(-100);
	box2->push_back(65535);
	box2->print();
	
	return 0;
}