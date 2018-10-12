cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(01_static_library LANGUAGES CXX)

add_library(Userclass-object
OBJECT
	userclass.hpp
	userclass.cpp
)

set_target_properties(Userclass-object
PROPERTIES
	POSITION_INDEPENDENT_CODE 1
) #for older compilers
  
add_library(Userclass-shared
SHARED
	$<TARGET_OBJECTS:Userclass-object>
)
set_target_properties(Userclass-shared
PROPERTIES
	OUTPUT_NAME "Userclass"
)
	
add_library(Userclass-static
STATIC
	$<TARGET_OBJECTS:Userclass-object>
)
set_target_properties(Userclass-static
PROPERTIES
	OUTPUT_NAME "Userclass"
)
add_executable(main main.cpp)

target_link_libraries(main Userclass-static)