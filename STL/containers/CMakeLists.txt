cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(cpp_stl LANGUAGES CXX)

list(APPEND examples
	std_map.cpp
	std_pair.cpp
	std_stack.cpp
	std_vector.cpp
)
foreach(_source IN LISTS examples)
	get_filename_component(exe_name ${_source} NAME_WE )
	add_executable(${exe_name} ${_source})
	set_target_properties(${exe_name}
	PROPERTIES
		CXX_STANDARD 17
		CXX_EXTENSIONS OFF
		CXX_STANDARD_REQUIRED ON	
		POSITION_INDEPENDENT_CODE 1
	)
endforeach()

