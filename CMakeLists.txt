cmake_minimum_required(VERSION 3.7)
project(bruteForce)
#Parametre
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++17")
#set(CMAKE_CXX_COMPILER "g++")
#SET_TARGET_PROPERTIES(main PROPERTIES LINKER_LANGUAGE CXX)

#Project
set(SRCS
	"sources/mainTest.cpp"
	"sources/utilities.cpp"
	"sources/word.cpp"
)

set(HEADERS
	"headers/utilities.hpp"
	"headers/word.hpp"
)

add_executable(bruteForce ${HEADERS} ${SRCS})
target_compile_options(imageEditor PUBLIC "-Wall")

#My libs
