#include <utility>
#include <tuple>
#include <vector>
#include <iostream>

class TCustom{
	public:
	TCustom(){std::cout << "TCustom default ctor\n";}
};
template<typename T> void bake_pair(T);

int main(int argc, char** argv) {
	
	// Ctor #1
	// pair();
	// constexpr pair();
	
	std::pair<int, char> p1;
	std::pair<TCustom, TCustom> p1c;

	
	// Ctor #2
	// pair( const T1& x, const T2& y );
	// constexpr pair( const T1& x, const T2& y );
	
	auto i{42};
	auto b{true};
	std::pair<int, bool> p2(i, b);
	
	
	// Ctor #3 
	// template< class U1, class U2 >pair( U1&& x, U2&& y );
	// template< class U1, class U2 >constexpr pair( U1&& x, U2&& y );
	
	std::pair<float, float> p3(3.14, 1.7);
	
	
	// Ctor #4 
	// template< class U1, class U2 >pair( const pair<U1, U2>& p );
	// template< class U1, class U2 >constexpr pair( const pair<U1, U2>& p );
	
	std::pair<int, char> p4(p1);
	
	
	// Ctor #5
	// template< class U1, class U2 > pair( pair<U1, U2>&& p );
	// template< class U1, class U2 > constexpr pair( pair<U1, U2>&& p );
	
	std::pair<bool, bool> p5(std::move(std::pair<bool, bool> (true, false)));
	
	
	// Ctor #6
	// template< class... Args1, class... Args2 >
	// pair(std::piecewise_construct_t,
	// 		std::tuple<Args1...> first_args,
	// 		std::tuple<Args2...> second_args );
	
	std::pair<std::vector<double>, std::string> p6(
		std::piecewise_construct, 
		std::forward_as_tuple(0.123, 7.7),
		std::forward_as_tuple(42, 'x'));
	
	// Ctor #7 #8 - Copy - Move
	// pair( const pair& p ) = default;
	// pair( pair&& p ) = default;
	
	// Member functions:
	// operator=
	std::pair<bool, bool> pm1(false, true);
	pm1 = p5;
	pm1 = std::pair<bool, bool>(true, true);
	
	auto [tag, number] = std::make_pair("Tag", 83);
	std::ignore = tag;
	std::ignore = number;
	
	
	// .swap()
	pm1.swap(p5);
	
	
	// Non-Member functions:
	// std::get<>()
	
	std::get<0>(p1) = 111;
	std::get<1>(p1) = '\n';
	
	// std::swap()
	std::swap(pm1, p5);
	
	// Relational operators
	if (p5 == pm1) std::cout << "p5 and pm1 are equal\n";
	if (p5 != pm1) std::cout << "p5 and pm1 are not equal\n";
	if (p5 <  pm1) std::cout << "p5 is less than pm1\n";
	if (p5 >  pm1) std::cout << "p5 is greater than pm1\n";
	if (p5 <= pm1) std::cout << "p5 is less than or equal to pm1\n";
	if (p5 >= pm1) std::cout << "p5 is greater than or equal to pm1\n";
	
	// Member types:
	// ::first_type
	// ::second_type
	bake_pair(std::make_pair(42,8));
	
	return 0;
}

// Member types:
template<typename T = std::pair<int, int>>
void bake_pair(T p_obj) {
	using pair_type_one = typename T::first_type;
	using pair_type_two = typename T::second_type;
	pair_type_one &a = p_obj.first;
	pair_type_two &b = p_obj.second;
	std::cout << a+b << '\n';
}



