cmake_minimum_required(VERSION 3.25)
project(geometric_shape_drawer)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
include_directories(src)

add_executable(geometric_shape_drawer
        main.cpp src/Shape.cpp inc/Shape.h src/Rectangle.cpp inc/Rectangle.h src/Rhombus.cpp inc/Rhombus.h src/Triangle.cpp inc/Triangle.h src/AcuteTriangle.cpp inc/AcuteTriangle.h)
