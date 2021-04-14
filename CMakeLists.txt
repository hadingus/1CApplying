cmake_minimum_required(VERSION 3.16)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe main.cpp reader.hpp ScanLine.hpp Geometry.hpp Geometry.cpp ScanLine.cpp)