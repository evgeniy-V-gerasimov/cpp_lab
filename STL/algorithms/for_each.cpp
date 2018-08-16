#include <algorithm>
#include <vector>
#include <iostream>

class function_object{
	public:
	function_object(): sum(0) {}
	int sum;
	void operator()(int &x) {
		sum += x;
	}
};

int subtract_free(int &x){
	return --x;
}

void print_vector(std::vector<int> &v){
	for(auto& it: v){
		std::cout << it << ' ';
	}
	std::cout << '\n';
}

int main(int argc, char** argv) {
	std::vector<int> integers {1,-1,42,9,33,5};
	
	
	std::for_each(integers.rbegin(), integers.rend(), subtract_free);
	print_vector(integers); // 0 -2 41 8 32 4
	
	auto f = std::for_each(integers.begin(), integers.end(), function_object());
	std::cout << f.sum << '\n'; // 83
	
	std::for_each(integers.rbegin(), integers.rend(), [](int &x){ ++x; });
	print_vector(integers); // 1 -1 42 9 33 5
	
	return 0;
}