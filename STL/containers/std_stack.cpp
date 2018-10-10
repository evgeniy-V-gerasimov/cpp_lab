#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <list>

class T;
int main(int argc, char** argv) {
	
// Ctor #1
//stack() : stack(Container()) { }
	std::stack<int> def_constructed;  // empty stack 

// Ctor #2 #3
//explicit stack( const Container& cont = Container() );
//explicit stack( const Container& cont );
//explicit stack( Container&& cont );

		std::deque<int> deq (3, 10); 
	std::stack<int> second (deq); // copy of deque<int>
	std::stack<int> third (std::move(deq));
	
// Ctor #4 #5
//stack( const stack& other );
//stack( stack&& other );

	std::stack<int> four (second);
	std::stack<int> five (std::move(third));

// Ctor #6 - #10
//template< class Alloc > explicit stack( const Alloc& alloc );
//template< class Alloc > stack( const Container& cont, const Alloc& alloc );
//template< class Alloc > stack( Container&& cont, const Alloc& alloc );
//template< class Alloc > stack( const stack& other, const Alloc& alloc );
//template< class Alloc > stack( stack&& other, const Alloc& alloc );
		std::vector<int> vec{1, 22, 333};
	std::stack<int, std::vector<int> > six; 
	std::stack<int, std::vector<int> > seven(vec);
	std::stack<int, std::list<int> > eight(std::move(std::list<int> {42,77}));

// Member functions:
//
// stack& operator=( stack&& other );

	six = seven;

// Element access.
//
//reference top();
//const_reference top() const;

	std::stack<int> st1({1,2,3,4,9});
	std::cout << "st1 top element: " << st1.top() << '\n';
	
// Capacity
//
//[[nodiscard]] bool empty() const;

	if(not st1.empty()) {std::cout << "st1 is not empty.\n";}
	
//size_type size() const;

	auto stack_size = st1.size();
	std::cout << "st1 size is: " << stack_size << '\n';
	
// Modifiers
//
//void push( const value_type& value );
//void push( value_type&& value );
	
	std::stack<char> st2;
	char ltr {'A'};
	st2.push(ltr);
	st2.push('k');
	
//void pop();

	st2.pop();
	std::cout << "st2 size is: " << st2.size() << '\n';

//template< class... Args > void emplace( Args&&... args );
//template< class... Args > decltype(auto) emplace( Args&&... args );

	std::stack<T> st3;
	st3.emplace();
	st3.emplace(42);
	
//void swap( stack& other ) noexcept

	std::stack<int> st4;
	st4.swap(st1);
	std::cout << "st4 size after swap: " << st4.size() << '\n';
	std::swap(st1, st4);
	
// Non-Member functions:
//
//template< class T, class Container >bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs );	
//template< class T, class Container >bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
//template< class T, class Container >bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs );	
//template< class T, class Container >bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
//template< class T, class Container >bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
//template< class T, class Container >bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

	if (st1 == st4) std::cout << "st1 and st4 are equal\n";
	if (st1 != st4) std::cout << "st1 and st4 are not equal\n";
	if (st1 <  st4) std::cout << "st1 is less than st4\n";
	if (st1 <= st4) std::cout << "st1 is less than or equal to st4\n";
	if (st1 >  st4) std::cout << "st1 is greater than st4\n";
	if (st1 >= st4) std::cout << "st1 is greater than or equal to st4\n";
	return 0;
}

class T{
	public:
	T() 			{std::cout << "T() default ctor. " << std::endl;}
	explicit T(int) {std::cout << "T(int) explicit ctor. " << std::endl;}
	~T()			{std::cout << "T() dtor. " << std::endl;}
};