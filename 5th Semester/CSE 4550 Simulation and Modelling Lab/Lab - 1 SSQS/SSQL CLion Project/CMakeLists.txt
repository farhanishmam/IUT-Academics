cmake_minimum_required(VERSION 3.19)
project(SSQL_CLion_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(SSQL_CLion_Project main.cpp event.cpp event.h server.cpp server.h queue.cpp queue.h scheduler.cpp scheduler.h)