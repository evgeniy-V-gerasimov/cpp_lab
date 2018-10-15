cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Factory_pattern LANGUAGES CXX)

list(APPEND flags
	"-Wall"
	"-Wextra"
	"-Wpedantic"	
)

add_executable(main main.cpp)

set_target_properties(main
	PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON
	POSITION_INDEPENDENT_CODE 1
)

target_compile_options(main
PRIVATE
	${flags}
)
target_link_libraries(main 
PRIVATE 
	-static
)