cmake_minimum_required(VERSION 3.7)
project(bruteForce)
#Parametre
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++17")
#set(CMAKE_CXX_COMPILER "g++")
#SET_TARGET_PROPERTIES(main PROPERTIES LINKER_LANGUAGE CXX)

#Project
set(SRCS
	"sources/brute_test_threads.cpp"
	"sources/utilities.cpp"
	"sources/word.cpp"
	"sources/thread_manager.cpp"
)

set(HEADERS
	"headers/utilities.hpp"
	"headers/word.hpp"
	"headers/thread_manager.hpp"
)

add_executable(bruteForce ${HEADERS} ${SRCS})
target_compile_options(bruteForce PUBLIC "-Wall")

#openssl lib
find_package(OpenSSL)
include_directories(${OPENSSL_INCLUDE_DIR})

#pthread lib
find_package(Threads)
include_directories(${CMAKE_THREAD_LIBS_INIT})

#link
target_link_libraries(bruteForce crypto Threads::Threads)
