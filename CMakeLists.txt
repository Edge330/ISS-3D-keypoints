cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(iss_3d)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (iss_3d iss_3d.cpp)
target_link_libraries (iss_3d ${PCL_LIBRARIES})
