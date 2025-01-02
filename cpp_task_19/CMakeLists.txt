cmake_minimum_required(VERSION 3.15)
project(boost_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Boost as a submodule
set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/../external/boost")

# Integrate Boost through its CMake
add_subdirectory(${BOOST_ROOT} external/boost-build)

# Find Boost using FindBoost module
find_package(Boost 1.86 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Could not find Boost!")
endif()

add_executable(boost_example main.cpp)

# Link Boost libraries
target_link_libraries(boost_example Boost::program_options)
