# run cmake --build build/ in terminal
cmake_minimum_required(VERSION 3.22.1) 
project(SimpleWindow)
add_library(${PROJECT_NAME} SHARED simple_window.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER simple_window.hpp)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib
				PUBLIC_HEADER DESTINATION include	
				)
