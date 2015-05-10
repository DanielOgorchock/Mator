cmake_minimum_required(VERSION 3.2)
project(mator)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_LIST_DIR}/build)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(include/)

add_library(mator STATIC
            include/mator/Mator.h
            include/mator/2Dim/Mat2.h
            include/mator/2Dim/Vec2.h
            include/mator/3Dim/Mat3.h
            include/mator/3Dim/Vec3.h
            include/mator/4Dim/Mat4.h
            include/mator/4Dim/Vec4.h
            src/Mat2.cpp
            src/Mat3.cpp
            src/Mat4.cpp
            src/Vec2.cpp
            src/Vec3.cpp
            src/Vec4.cpp)