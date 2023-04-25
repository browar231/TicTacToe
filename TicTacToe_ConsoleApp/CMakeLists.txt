cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe_ConsoleApp VERSION 0.1.0)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

###don't know why but it brokes build process
# set(TICTACTOE_CORE_EXTERNAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Core CACHE PATH "TICTACTOE_CORE")
# add_subdirectory(${TICTACTOE_CORE_EXTERNAL_SOURCE_DIR} TICTACTOE_CORE)

add_executable(${PROJECT_NAME}
    ${SOURCE_DIR}/Console.cpp
    ${SOURCE_DIR}/ConsoleApp.cpp
    ${SOURCE_DIR}/PlayerConsole.cpp
    ${SOURCE_DIR}/main.cpp)

target_link_libraries(${PROJECT_NAME} TicTacToe_Core)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
