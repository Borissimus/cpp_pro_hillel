cmake_minimum_required(VERSION 3.15)
project(boost_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Boost as a submodule
set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/../external/boost/dist")

# Integrate Boost through its CMake
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")
set(Boost_NO_SYSTEM_PATHS ON)

# Find Boost using FindBoost module
find_package(Boost 1.86 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${BOOST_LIBRARYDIR})
else()
    message(FATAL_ERROR "Could not find Boost!")
endif()

add_executable(boost_example main.cpp)

# Link Boost libraries
target_link_libraries(boost_example Boost::program_options)
