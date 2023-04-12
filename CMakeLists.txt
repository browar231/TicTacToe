cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${SOURCE_DIR}/*.cpp")
if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${source_files})
endif()
if(UNIX)
    add_executable(${PROJECT_NAME} ${source_files})
endif()
target_include_directories(${PROJECT_NAME}
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/inc
)
