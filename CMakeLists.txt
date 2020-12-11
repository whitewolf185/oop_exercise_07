cmake_minimum_required(VERSION 3.17)
project(oop_exercise_07)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_exercise_07 main.cpp
        Figures.h
        Rectangle.h
        Rhombus.h
        Trapeze.h
        factory.h
        document.h)