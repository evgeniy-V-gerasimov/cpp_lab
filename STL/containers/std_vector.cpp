#include <utility>
#include <vector>
#include <iostream>

class T;
int main(int argc, char** argv) {

// Ctor #1
//vector() noexcept(noexcept(Allocator()));
//explicit vector( const Allocator& alloc ) noexcept;
	std::vector<int> va1;
	
// Ctor #2
//vector( size_type count, const T& value, const Allocator& alloc = Allocator());

	std::vector<int> va2(42, 1);

// Ctor #3
//explicit vector( size_type count, const Allocator& alloc = Allocator() );

	std::vector<T> va3(3);

// Ctor #4
//template< class InputIt >vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

	std::vector<int> va4(va2.begin(), va2.end()-12 );
	
// Ctor #5
//vector( const vector& other, const Allocator& alloc );

	std::vector<int> va5(va4);

// Ctor #6, #7
//vector( vector&& other ) noexcept;
//vector( vector&& other, const Allocator& alloc );
	std::vector<char> va6(std::move(std::vector<char>{'a','b','c'}) );

// Ctor #8
//vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() );
	std::vector va8 {2.0, 8.3, 3.1};
	
// Member functions:
//
//vector& operator=( const vector& other );
//vector& operator=( vector&& other );
//vector& operator=( std::initializer_list<T> ilist );

	va1 = va2;

	va1 = std::move(std::vector<int>{1,2,3});

	va1 = {3,2,1};

//void assign( size_type count, const T& value );
//template< class InputIt > void assign( InputIt first, InputIt last );
//void assign( std::initializer_list<T> ilist );

	va1.assign(12, 0);
	
	va1.assign(va2.begin()+20, va2.end()-20);
	
	va1.assign({33,87,22,51});

//allocator_type get_allocator() const;
	auto allocator_va1 = va1.get_allocator();

// Element access:
//
//reference       at( size_type pos );
//const_reference at( size_type pos ) const;

	int& tmp = va1.at(1);

//reference       operator[]( size_type pos );
//const_reference operator[]( size_type pos ) const;

	tmp = va1[4];
	
//reference front();
//const_reference front() const;

	auto& va1_first_element_ref = va1.front();
	va1_first_element_ref = 10;

//reference back();
//const_reference back() const;

	auto& va1_last_element_ref = va1.back();
	va1_last_element_ref = 8;

//T* data() noexcept;
//const T* data() const noexcept;

	int* va1_data = va1.data();
	if(va1_data != nullptr)	std::cout << "va1_data first array element: " << va1_data[0] << '\n';
	
// Iterators:
//
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//const_iterator cbegin() const noexcept;

	std::vector<int>::iterator begin_iter {va1.begin()};
	*begin_iter = 6;
	
	std::vector<int>::const_iterator cbegin_iter {va1.cbegin()};
	std::cout << "cbegin_iter: " << *cbegin_iter << '\n';
	
//iterator end() noexcept;
//const_iterator end() const noexcept;
//const_iterator cend() const noexcept;
	
	auto va1_end = va1.end();
	for (auto it = va1.begin() ; it != va1_end; ++it) {
		std::cout << *it << ' ';
	} std::cout << std::endl;
	
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//const_reverse_iterator crbegin() const noexcept;
{
	auto rev_it = va1.rbegin();
	
//reverse_iterator rend() noexcept;
//const_reverse_iterator rend() const noexcept;
//const_reverse_iterator crend() const noexcept;

	auto va1_reverse_end = va1.rend();
	for ( ; rev_it != va1_reverse_end; ++rev_it) {
		std::cout << *rev_it << ' ';
	} std::cout << std::endl;
}
// Capacity:
//
//bool empty() const noexcept;
//[[nodiscard]] bool empty() const noexcept;

	if(not va2.empty()) std::cout << "va2 is not empty.\n" ;

//size_type size() const noexcept;
	
	auto va2_size {va2.size()};
	std::cout << "va2 size: " << va2_size << '\n';

//size_type max_size() const noexcept;

	auto va2_max_size {va2.max_size()};
	std::cout << "va2 max size: " << va2_max_size << '\n';
	
//void reserve( size_type new_cap );

	va2.reserve(50);

//size_type capacity() const noexcept;

	auto va2_cap {va2.capacity()};
	std::cout << "va2 capacity size: " << va2_cap << '\n';

//void shrink_to_fit();

	va2.shrink_to_fit();
	std::cout << "va2 capacity after shrinking: " << va2.capacity() << '\n';

//void clear() noexcept;

	va2.clear();
	std::cout << "va2 size after clearing: " << va2.size() << "  capacity: " << va2.capacity() << '\n';

//iterator insert( const_iterator pos, const T& value );
//iterator insert( const_iterator pos, T&& value );
//iterator insert( const_iterator pos, size_type count, const T& value );
//template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );
//iterator insert( const_iterator pos, std::initializer_list<T> ilist );

	int c_array[] = {0,0,0};
	auto iter_insert1 = va4.insert(va4.begin()+5, 256);
	std::cout << "value inserted: "<< *iter_insert1 << '\n';

	va4.insert(va4.begin(), 4, 7);
	
	auto iter_insert2 = va4.insert(iter_insert1, va1.begin(), va1.begin()+3);
	iter_insert2 = va4.insert(iter_insert2, c_array, c_array+3);
	
	iter_insert2 = va4.insert(iter_insert2, {1024, 65'535});
	
	for (auto it {va4.begin()} ; it != va4.end(); ++it) {
		std::cout << *it << ' ';
	} std::cout << std::endl;
	
//template< class... Args > iterator emplace( const_iterator pos, Args&&... args );
	
	auto emplace_iter = va6.emplace(va6.end(), 'e');
	emplace_iter = va6.emplace(emplace_iter, 'd');

	for (auto it {va6.begin()} ; it != va6.end(); ++it) {
		std::cout << *it << ' ';
	} std::cout << std::endl;
	
//template< class... Args >reference emplace_back( Args&&... args );

	auto& letter_ref = va6.emplace_back('f');
	std::cout << "letter - " <<  letter_ref << " - emplaced\n"; 
	
//iterator erase( const_iterator pos );
//iterator erase( const_iterator first, const_iterator last );

	auto erase_iter1 = va6.erase(va6.begin());
	std::cout << "after erase iterator points to: " << *erase_iter1 << '\n';

	auto erase_iter2 = va4.erase(va4.begin(), va4.begin()+10);
	std::cout << "after erase iterator points to: " << *erase_iter2 << '\n';

//void push_back( T&& value );

	std::vector<std::string> words;
	words.push_back("mouse");
	words.push_back(std::move(std::string{"laptop"}));

//void pop_back();

	std::vector numbers {1,2,3,42};
	numbers.pop_back();
	std::cout << "numbers size: " << numbers.size() << '\n';

//void resize( size_type count );
//void resize( size_type count, const value_type& value );

	numbers.resize(5);
	
	numbers.resize(10, 256);
	
	for (auto& el: numbers) std::cout << el << ' ';
    std::cout << '\n';

//void swap( vector& other ) noexcept;
	
	numbers.swap(va1);

//Non-member functions:
//
//template< class T, class Alloc > bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//template< class T, class Alloc > bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//template< class T, class Alloc > bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//template< class T, class Alloc > bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//template< class T, class Alloc > bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//template< class T, class Alloc > bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );	

if (va1 == va2) std::cout << "va1 and va2 are equal\n";
if (va1 != va2) std::cout << "va1 and va2 are not equal\n";
if (va1 <  va2) std::cout << "va1 is less than va2\n";
if (va1 <= va2)	std::cout << "va1 is less than or equal to va2\n";
if (va1 >  va2) std::cout << "va1 is greater than va2\n";
if (va1 >= va2) std::cout << "va1 is greater than or equal to va2\n";
	
	
//template< class T, class Alloc > void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs ) noexcept;

	std::swap(numbers, va1);

	return 0;	
}


class T{
	public:
	T()	{std::cout << "T() default ctor. " << std::endl;}
	~T(){std::cout << "T() dtor. " << std::endl;}
};