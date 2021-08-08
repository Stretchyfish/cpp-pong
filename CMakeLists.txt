cmake_minimum_required(VERSION 3.0.0)
project(cpp-pong VERSION 0.1.0)

add_executable(cpp-pong src/main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# SFML library setup
set(SFML_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML-2.5.1)
include_directories(${SFML_SOURCE}/include)
target_link_libraries(cpp-pong ${SFML_SOURCE}/lib)

