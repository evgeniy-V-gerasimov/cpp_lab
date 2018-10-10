project(main)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fext-numeric-literals -Wall -O2 -static-libgcc -static-libstdc++ -static -lpthread") 
# -static-libgcc -static-libstdc++  ARE here to remove dependencies from: LIBGCC_S_DW2-1.DLL LIBSTDC++-6.DLL 
# -static -lpthread                 LIBWINPTHREAD-1.DLL

message(STATUS "<> [${PROJECT_NAME}]")			
add_executable(for_each for_each.cpp)
add_executable(sort sort.cpp)

