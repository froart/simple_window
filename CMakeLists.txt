cmake_minimum_required(VERSION 3.22.1) 
project(simple_window)
add_library(${PROJECT_NAME} simple_window.cpp)
target_link_libraries(${PROJECT_NAME} SDL2)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER simple_window.hpp)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib
				PUBLIC_HEADER DESTINATION include	
				)
