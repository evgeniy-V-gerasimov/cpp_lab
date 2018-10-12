cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(03_conditionals LANGUAGES CXX)

#set(USE_LIBRARY ON) # maintainer can change this 

option(USE_LIBRARY "Compile sources into a library" OFF) 
# to switch option: 
# $ cmake -D USE_LIBRARY=ON -G "Mingw Makefiles" ..

include(CMakeDependentOption)
cmake_dependent_option(
	MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
	"USE_LIBRARY" ON
)						#If USE_LIBRARY is ON, MAKE_STATIC_LIBRARY defaults to OFF
cmake_dependent_option(
	MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON  
	"USE_LIBRARY" ON
) 						#If USE_LIBRARY is ON, MAKE_SHARED_LIBRARY defaults to ON

message(STATUS "<> MAKE_STATIC_LIBRARY ${MAKE_STATIC_LIBRARY}")
message(STATUS "<> MAKE_SHARED_LIBRARY ${MAKE_SHARED_LIBRARY}")

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

set(BUILD_SHARED_LIBS OFF)

list(APPEND _sources 
	userclass.hpp
	userclass.cpp
)

if(USE_LIBRARY)
	add_library(Userclass ${_sources})

	add_executable(main main.cpp)

	target_link_libraries(main Userclass)

else()

	add_executable(main main.cpp ${_sources})

endif()

# true 
#set(USER_BOOL_VALUE 1)
#set(USER_BOOL_VALUE ON)
#set(USER_BOOL_VALUE YES)
#set(USER_BOOL_VALUE TRUE)
#set(USER_BOOL_VALUE Y)
#set(USER_BOOL_VALUE 42)

# false
#set(USER_BOOL_VALUE 0)
#set(USER_BOOL_VALUE OFF)
#set(USER_BOOL_VALUE NO)
#set(USER_BOOL_VALUE FALSE)
#set(USER_BOOL_VALUE N)
#set(USER_BOOL_VALUE IGNORE)
#set(USER_BOOL_VALUE NOTFOUND)
#set(USER_BOOL_VALUE "")
set(USER_BOOL_VALUE abcd-NOTFOUND)
if(NOT USER_BOOL_VALUE) 
	message(STATUS "BOOL = FALSE = ${USER_BOOL_VALUE}")
else()
	message(STATUS "BOOL = TRUE = ${USER_BOOL_VALUE}")
endif()
