cmake_minimum_required(VERSION 3.10)

set(SOURCES 
	main.cpp
	task_controller.cpp
	task_view.cpp
	task_manager.cpp)

project(to_do_manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} ${SOURCES})
