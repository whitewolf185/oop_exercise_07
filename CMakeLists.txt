cmake_minimum_required(VERSION 3.17)
project(oop_exercise_07)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_exercise_07 main.cpp
        Coord.h
        Figures.h
        Rectangle.cpp Rectangle.h
        Rhombus.cpp Rhombus.h
        Trapeze.cpp Trapeze.h)