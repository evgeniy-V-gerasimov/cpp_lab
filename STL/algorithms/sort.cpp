#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <string_view>

namespace cpp_lab {
	
template<typename Container>
void print(Container &c, std::string_view s){
	std::cout << s << '\n';
	for(auto& it: c) {
		std::cout << it << ' ';
	}
	std::cout << '\n';
}

}

int main(int argc, char** argv) {
	using cpp_lab::print;
	
	std::array<int, 15> numbers1 {11, 5, 6, 13, 0, 3, 4, 7, 10, 12, 2, 9, 1, 14, 8};
	print(numbers1, "Initialized array: ");

	std::sort(numbers1.begin(), numbers1.end());	
	print(numbers1, "Sorted array: ");
	
	std::sort(numbers1.begin(), numbers1.end(), std::greater<int>());
	print(numbers1, "Sorted with greater<int>(): ");
	
	std::array<int, 15> numbers2 {11, 5, 6, 13, 0, 3, 4, 7, 10, 12, 2, 9, 1, 14, 8};
	std::partial_sort(numbers2.begin(), numbers2.begin() + 8, numbers2.end());
	print(numbers2, "Sorted with partial_sort, first 8 numbers: ");
	
	std::array<int, 8> numbers3 {11, 5, 6, 13, 1, 7, 3, 0};
	std::array<int, 4> numbers4 {0, 0, 0, 0};
	std::array<int, 8> numbers5 {10, 11, 12, 13, 14, 15, 16, 17};
	auto it1 = std::partial_sort_copy(numbers3.begin(), numbers3.end()
									, numbers4.begin(), numbers4.end());
	print(numbers4, "Sorted with partial_sort_copy: ");
	if (it1 == numbers4.end() ) std::cout << "iterator points to numbers4.end()\n";
	
	auto it2 = std::partial_sort_copy(numbers3.begin(), numbers3.end()
									, numbers5.begin(), numbers5.end(), std::greater<int>());
	print(numbers5, "Sorted with partial_sort_copy, descending order: ");
	if (it2 == numbers5.end() ) std::cout << "iterator points to numbers5.end()\n";
	
	
	std::array<int, 14> numbers6 {11, 5, 6, 13, 0, 3, 4, 1, 10, 12, 2, 9, 7, 8};
	std::nth_element(numbers6.begin(), numbers6.begin() + 7, numbers6.end());
	print(numbers6, "Sorted with nth_element: ");
	
	std::nth_element(numbers6.begin(), numbers6.begin()+1, numbers6.end(), std::greater<int>());
    std::cout << "The second largest element is " << numbers6.at(1) << '\n';
	
	std::array<int, 8> numbers7 {1, 4, 7, 2, 3, 5, 6, 8 }; // having two sorted parts - 147 and 23568
	std::inplace_merge(numbers7.begin(), numbers7.begin()+3, numbers7.end());
	print(numbers7, "Sorted with inplace_merge: ");
	
	std::array<int, 8> numbers8 {8, 5, 7, 2, 3, 4, 6, 1 };
	std::stable_sort(numbers8.begin(), numbers8.end());
	print(numbers8, "Sorted with stable_sort: ");
	return 0;
}