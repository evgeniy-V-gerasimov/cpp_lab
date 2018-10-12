cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(06_compiler_flags LANGUAGES CXX)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
message("GNU GCC")
endif()

list(APPEND flags 
	"-Wall"
	"-Wextra"
	"-Wpedantic"
)

add_library(modules
STATIC
	a.hpp
	a.cpp
	b.hpp
	b.cpp
)

target_compile_options(modules
PRIVATE							# PRIVATE attribute applies only to targets consuming it, and not other targets; 
	${flags}					# INTERFACE compile options on a given target will only be applied to targets consuming it;
)								# PUBLIC compile options will be applied to the given target and all other targets consuming it;

add_executable(main main.cpp)

target_compile_options(main
PRIVATE
	"-fPIC"
)
target_link_libraries(main modules)
