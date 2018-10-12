cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(09_os-detection LANGUAGES CXX)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	message(STATUS "Configuring on/for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	message(STATUS "Configuring on/for macOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	message(STATUS "Configuring on/for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
	message(STATUS "Configuring on/for IBM AIX")
else()
	message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()

add_executable(main main.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(main PUBLIC "IS_LINUX")	# add_definitions() modifies compile definitions for entire project
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_definitions(main PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(main PUBLIC "IS_WINDOWS")
endif()