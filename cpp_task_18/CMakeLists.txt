cmake_minimum_required(VERSION 3.10)

project(std_shared_ptr_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(shared_ptr_lib)

add_executable(std_shared_ptr_lib main.cpp)

target_link_libraries(std_shared_ptr_lib PRIVATE CustomSharedPtr)
