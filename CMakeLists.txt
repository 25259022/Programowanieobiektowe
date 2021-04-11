cmake_minimum_required(VERSION 3.17)
project(Programowanieobiektowe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(Programowanieobiektowe main.cpp menu.cpp menu.h pliki.cpp pliki.h tablica.cpp tablica.h tablica_wysw.cpp )

