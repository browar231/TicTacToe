cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe_Core VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_library(${PROJECT_NAME} SHARED 
    ${SOURCE_DIR}/Board.cpp
    ${SOURCE_DIR}/Player.cpp
    ${SOURCE_DIR}/PlayerCPU.cpp
    ${SOURCE_DIR}/TicTacToe.cpp)
target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
