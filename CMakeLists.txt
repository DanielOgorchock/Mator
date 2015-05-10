cmake_minimum_required(VERSION 3.2)
project(mator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(mator ${SOURCE_FILES})