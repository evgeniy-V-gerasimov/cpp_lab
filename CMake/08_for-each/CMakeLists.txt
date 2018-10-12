cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(08_for-each LANGUAGES CXX)

# different ways of using foreach
foreach(loop_var1 RANGE 42 30 [step])
	message(STATUS "Iterating: ${loop_var1}")
endforeach()

foreach(loop_var2 "explicit1" "explicit2")
	message(STATUS "  Iterating: ${loop_var2}")
endforeach()

foreach(loop_var3 RANGE 4)
	message(STATUS "    Iterating: ${loop_var3}")
endforeach()

add_library(modules
STATIC
	a.hpp
	a.cpp
	b.hpp
	b.cpp
	c.hpp
	c.cpp
	d.hpp
	d.cpp
)

target_compile_options(modules
PRIVATE
	-O3
)

list(APPEND lowered_optimization_list
	c.cpp
	d.cpp
)
message(STATUS "Setting source properties:")
foreach(_source IN LISTS lowered_optimization_list)
	set_source_files_properties(${_source} 
	PROPERTIES
		COMPILE_FLAGS -O2
	)
	message(STATUS "Appending -O2 flag for ${_source}")
endforeach()

message(STATUS "Querying sources properties:")
foreach(_source ${lowered_optimization_list})
	get_source_file_property(_flags ${_source} COMPILE_FLAGS)
	message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()





add_executable(main main.cpp)

target_link_libraries(main modules)
