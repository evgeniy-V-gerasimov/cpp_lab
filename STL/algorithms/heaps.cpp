#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>


namespace cpp_lab {
	
template<typename Container>
void print(Container c, std::string_view s){
	std::cout << s << '\n';
	for(auto& it: c){
		std::cout << it << ' ';
	}
	std::cout << '\n';
}

}

int main(int argc, char** argv) {
	using cpp_lab::print;
	std::array<int, 15> numbers {11, 5, 6, 13, 0, 3, 4, 7, 10, 12, 2, 9, 1, 14, 8};
	print(numbers, "Initialized array: ");
	
	std::make_heap(std::begin(numbers), std::end(numbers)); // this creates a heap ordered list
	print(numbers, "make_heap: ");
	
	numbers.at(9) = 15;
	std::push_heap(numbers.begin(), numbers.end()); // 15 makes its way to the top of the heap
	print(numbers, "push_heap: ");
	
	std::pop_heap(numbers.begin(), numbers.end());
	numbers.at(14) = 0; // top element moves to last position, and should be removed 
	print(numbers, "pop_heap: ");
	
	std::sort_heap(numbers.begin(), numbers.end());
	print(numbers, "sort_heap: ");
	return 0;
}

//		     14
//      13         11
//  10     12    9     8
// 7  5   0  2  3 1   4  6


