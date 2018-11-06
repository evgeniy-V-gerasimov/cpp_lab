#include <utility>
#include <map>
#include <vector>
#include <iostream>

template<typename Map>
void print_map(Map& m) {
	std::cout << "{\n";
	for(auto& [key, value]: m) {
		std::cout << '\t' << key << ':' << value << '\n';
	}
	std::cout << "}\n";
}

int main(int argc, char** argv) {

// Member functions:
//
// Ctor #1
//explicit map( const Allocator& alloc );
std::map<int, std::string> mc1;
std::map<int, std::string> mct;

// Ctor #2
//template< class InputIterator > 
//map( InputIterator first, InputIterator last, const Allocator& alloc );
std::vector<std::pair<int,std::string>> v1 {{42,"boo"}, {1,"foo"}, {255,"zoo"}};
std::map<int, std::string> mc2(v1.begin(), v1.end());

// Ctor #3
//map( const map& other, const Allocator& alloc );
std::map<int, std::string> mc3(mc2);


std::map<int, std::string> temp(v1.begin(), v1.end());
// Ctor #4
//map( map&& other, const Allocator& alloc );
std::map<int, std::string> mc4(std::move(temp));

// Ctor #5
//map( std::initializer_list<value_type> init, const Allocator& );
std::map<int, std::string> mc5 {{12,"baz"}, {3,"foo"}, {77,"bar"}};

//map& operator=( const map& other );
//map& operator=( map&& other ) noexcept(/* see below */);
//map& operator=( std::initializer_list<value_type> ilist );
{
	mc1 = mc2;
	mc2 = {{111,"pop"}, {5,"foo"}, {34,"doo"}};
	mct = mc2;
	mc1 = std::move(mc2);
}

// Element access:
//
//T& at( const Key& key );
//const T& at( const Key& key ) const;
// _throws_ std::out_of_range if key element does not exist
{
	auto& t1 =  mc1.at(5);
	std::cout << t1 << '\n';
}

//T& operator[]( const Key& key );
//T& operator[]( Key&& key );
{
	auto& t2 = mc1[34];
	std::cout << t2 << '\n';
	mc1[42] = "vim";
	print_map(mc1);
}

// Iterators:
//
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//const_iterator cbegin() const noexcept;
{
	std::map<int,std::string>::iterator mc1_it = mc1.begin();
	std::map<int,std::string>::const_iterator mc1_const_it = mc1.cbegin();
}
//iterator end() noexcept;
//const_iterator end() const noexcept;
//const_iterator cend() const noexcept;
{
	std::map<int,std::string>::iterator mc1_it = mc1.end();
	std::map<int,std::string>::const_iterator mc1_const_it = mc1.cend();
}
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//const_reverse_iterator crbegin() const noexcept;
{
	std::map<int,std::string>::reverse_iterator mc1_rev_it = mc1.rbegin();
	std::map<int,std::string>::const_reverse_iterator mc1_const_rev_it = mc1.crbegin();
}
//reverse_iterator rend() noexcept;
//const_reverse_iterator rend() const noexcept;
//const_reverse_iterator crend() const noexcept;
{
	std::map<int,std::string>::reverse_iterator mc1_rev_it = mc1.rend();
	std::map<int,std::string>::const_reverse_iterator mc1_const_rev_it = mc1.crend();
}

// Capacity:
//
//[[nodiscard]] bool empty() const noexcept;
{
	bool isEmpty = mc1.empty();
}

//size_type size() const noexcept;
{
	auto mc1_size = mc1.size();
}

//size_type max_size() const noexcept;
{
	auto mc1_max = mc1.max_size();
}

// Modifiers:
//
//void clear() noexcept;
{
	mc1.clear();
}

//std::pair<iterator,bool> insert( const value_type& value );
//template< class P > std::pair<iterator,bool> insert( P&& value );
//std::pair<iterator,bool> insert( value_type&& value );
//iterator insert( const_iterator hint, const value_type& value );
//template< class P >iterator insert( const_iterator hint, P&& value );
//iterator insert( const_iterator hint, value_type&& value );
//template< class InputIt >void insert( InputIt first, InputIt last );
//void insert( std::initializer_list<value_type> ilist );
//insert_return_type insert(node_type&& nh);
//iterator insert(const_iterator hint, node_type&& nh);
{
	std::pair<int, std::string> pr1 {1, "goo"};
	auto [iter_mc1, good_insert] = mc1.insert(pr1);
	if(good_insert) std::cout << "iter_mc1: " << iter_mc1->second << '\n';
}
{
	auto [res_iter, good_insert] = mc1.insert({2, "voo"});
	auto iter_mc1 = mc1.insert(res_iter, {3, "koo"});
	std::cout << "iter_mc1: " << iter_mc1->second << '\n';
}
{
	mc1.insert(v1.begin(), v1.end());
	mc1.insert({{12,"baz"}, {3,"foo"}, {77,"bar"}});
	print_map(mc1);
}
{
	std::map<int, std::string>::node_type node = mc3.extract(255);
	node.key() = 4;
	auto irt = mc1.insert(std::move(node));
	if(irt.inserted) std::cout << "insert successfull\n";
	print_map(mc1);
}
{
	auto node = mct.extract(111);
	auto c_iter = mc1.find(77);
	auto iter_mc1 = mc1.insert(c_iter, std::move(node));
	std::cout << "iter_mc1: " << iter_mc1->second << '\n';
	print_map(mc1);
}

//template <class M>pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
//template <class M>pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
//template <class M>iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
//template <class M>iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);
{
	std::string t1 = {"temp"};
	std::string t2 = {"lol"};
	
	auto [iter1, reslt] = mc1.insert_or_assign(3, t1);
	std::cout << "iter1: " << iter1->second << '\n';
	
	auto iter2 = mc1.insert_or_assign(iter1, 4, t2);
	std::cout << "iter2: " << iter2->second << '\n';
	print_map(mc1);
}

//template< class... Args > std::pair<iterator,bool> emplace( Args&&... args );
{
	auto [iter_mc5, reslt] = mc5.emplace(std::make_pair(87, "kee"));
	auto r = mc5.emplace(35, "daa");
	print_map(mc5);
}

//template <class... Args> iterator emplace_hint( const_iterator hint, Args&&... args );
{
	auto hint_iter = mc5.begin(); 
	auto iter1 = mc5.emplace_hint(hint_iter, 5, "wee");
	auto iter2 = mc5.emplace_hint(iter1, std::make_pair(6, "ioo"));
	print_map(mc5);
}

//template <class... Args>pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
//template <class... Args>pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
//template <class... Args>iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
//template <class... Args>iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);

{
	auto [iter1, reslt] = mc5.try_emplace(4, "xxx");
	if(reslt) {
		std::cout << "try_emplace succeded \n";
	}
	auto iter2 =  mc5.try_emplace(iter1, 4, "yyy");
	print_map(mc5);
}

//iterator erase( iterator pos );
//iterator erase( const_iterator first, const_iterator last );
//size_type erase( const key_type& key );
{
	std::map<int, std::string>::const_iterator it = mc5.find(6);
	auto iter = mc5.erase(mc5.cbegin(), it);
	iter = mc5.erase(iter);
	auto count_rem = mc5.erase(87);
	std::cout << "Number of elements removed: " << count_rem  << '\n';
	print_map(mc5);
}


//void swap( map& other ) noexcept(/* see below */);
{
	mc5.swap(mc1);
	print_map(mc5);
}

//node_type extract( const_iterator position );
//node_type extract( const key_type& x );
{
	auto node_hndl = mc5.extract(2);
	node_hndl.key() = 13;
	mc5.insert(std::move(node_hndl));
	print_map(mc5);
}

//template<class C2>void merge(std::map<Key, T, C2, Allocator>& source);
//template<class C2>void merge(std::map<Key, T, C2, Allocator>&& source);
//template<class C2>void merge(std::multimap<Key, T, C2, Allocator>& source);
//template<class C2>void merge(std::multimap<Key, T, C2, Allocator>&& source);
{
	mc2.merge(mc5);
	std::cout << "Merged mc2 with mc5" << '\n';
	print_map(mc2);
}

// Lookup:
//
//template< class K > size_type count( const K& x ) const;
{
	auto count_key = mc2.count(3);
	std::cout << "Counted elements in mc2 with key = 3: " << count_key << '\n';
}

//iterator find( const Key& key );
//const_iterator find( const Key& key ) const;
//template< class K > iterator find( const K& x );
//template< class K > const_iterator find( const K& x ) const;
{
	auto iter = mc2.find(3);
	std::cout << "Found key 3, with value = \'" << iter->second << "\'\n";
	
}

//bool contains( const Key& key ) const;
//template< class K > bool contains( const K& x ) const;
{
	//C++20 feature
	//if(mc2.contains(3)) std::cout << "Contains key = 3" << '\n';
}

//template< class K > std::pair<iterator,iterator> equal_range( const K& x );
//template< class K > std::pair<const_iterator,const_iterator> equal_range( const K& x ) const;
{
	auto [range_bgn1, range_end1] = mc2.equal_range(41);
		
		std::cout << "range_bgn1 : Key = " << range_bgn1->first << " Value = " << range_bgn1->second << '\n';
		std::cout << "range_end1 : Key = " << range_end1->first << " Value = " << range_end1->second 
				  << "\n_________________________________\n";
		
	auto [range_bgn2, range_end2] = mc2.equal_range(42);
		
		std::cout << "range_bgn2 : Key = " << range_bgn2->first << " Value = " << range_bgn2->second<< '\n';
		std::cout << "range_end2 : Key = " << range_end2->first << " Value = " << range_end2->second<< '\n';
	
}

//template< class K > iterator lower_bound(const K& x);
//template< class K > const_iterator lower_bound(const K& x) const;
{
	auto iter = mc2.lower_bound(41);
	std::cout << "lower_bound(41) - " << iter->first << '\n';
	
}

//template< class K > iterator upper_bound( const K& x );
//template< class K > const_iterator upper_bound( const K& x ) const;
{
	auto iter = mc2.upper_bound(42);
	std::cout << "upper_bound(42) - " << iter->first << '\n';
	print_map(mc2);
}

// Observers:
//
//key_compare key_comp() const;
{
	std::map<int, std::string>::key_compare  kcmpr = mc2.key_comp(); 
	bool cmpr_res = kcmpr(1, 3);
	if(cmpr_res) std::cout << "key_compare() : compare true" << '\n';
}

//std::map::value_compare value_comp() const;
{
	auto vcmpr = mc2.value_comp(); 
	bool cmpr_res = vcmpr(std::make_pair<int, std::string>(1, "foo")
						, std::make_pair<int, std::string>(2, "foo"));
	if(cmpr_res) std::cout << "value_comp() : compare true" << '\n';
}


//template< class Key, class T, class Compare, class Alloc >
//bool operator==( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
//template< class Key, class T, class Compare, class Alloc >
//bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
//template< class Key, class T, class Compare, class Alloc >
//bool operator<( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
//template< class Key, class T, class Compare, class Alloc >
//bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
//template< class Key, class T, class Compare, class Alloc >
//bool operator>( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
//template< class Key, class T, class Compare, class Alloc >
//bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

if (mc2 == mct) std::cout << "mc2 and mct are equal\n";
if (mc2 != mct) std::cout << "mc2 and mct are not equal\n";
if (mc2 <  mct) std::cout << "mc2 is less than mct\n";
if (mc2 <= mct) std::cout << "mc2 is less than or equal to mct\n";
if (mc2 >  mct) std::cout << "mc2 is greater than mct\n";
if (mc2 >= mct) std::cout << "mc2 is greater than or equal to mct\n";

	print_map(mc2);
	print_map(mct);

//template< class Key, class T, class Compare, class Alloc >
//void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ) noexcept;
	std::swap(mc2, mct);
	
	return 0;	
}