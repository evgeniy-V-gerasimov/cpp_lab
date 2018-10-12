cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(07_lang_standard LANGUAGES CXX)

add_library(modules
SHARED
	a.hpp
	a.cpp
	b.hpp
	b.cpp
)
set_target_properties(modules
PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON	# if -std=c++17 not available CMake stops configuration with error
	POSITION_INDEPENDENT_CODE 1
)
add_executable(main main.cpp)

set_target_properties(main
PROPERTIES
	CXX_STANDARD 11
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
)

target_link_libraries(main modules)