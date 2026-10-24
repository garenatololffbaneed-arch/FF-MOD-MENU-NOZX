cmake_minimum_required(VERSION 3.18)
project(aimbot CXX)

add_library(aimbot SHARED aimbot.cpp)

find_library(log-lib log)
target_link_libraries(aimbot ${log-lib} dl)
