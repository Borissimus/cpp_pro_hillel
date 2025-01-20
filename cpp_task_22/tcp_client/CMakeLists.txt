cmake_minimum_required(VERSION 3.15)
project(boost_tcp_client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/../../external/boost/dist")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")
set(Boost_NO_SYSTEM_PATHS ON)



find_package(Boost 1.86 REQUIRED COMPONENTS system HINTS "${BOOST_ROOT}")

if(Boost_FOUND)
	message(STATUS "Boost Include Directories: ${Boost_INCLUDE_DIRS}")
	message(STATUS "Boost Libraries: ${Boost_LIBRARIES}")
    include_directories(${BOOST_INCLUDEDIR})
    link_directories(${BOOST_LIBRARYDIR})
else()
    message(FATAL_ERROR "Could not find Boost!")
endif()

add_executable(boost_tcp_client main.cpp)

target_link_libraries(boost_tcp_client Boost::system)

