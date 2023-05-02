cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe_wxApp VERSION 0.1.0)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

###don't know why but it brokes build process
# set(TICTACTOE_CORE_EXTERNAL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Core CACHE PATH "TICTACTOE_CORE")
# add_subdirectory(${TICTACTOE_CORE_EXTERNAL_SOURCE_DIR} TICTACTOE_CORE)

add_executable(${PROJECT_NAME}
    ${SOURCE_DIR}/MainApp.cpp
    ${SOURCE_DIR}/MainFrame.cpp
    ${SOURCE_DIR}/TicTacToe_wxApp.cpp
    ${SOURCE_DIR}/Player_wxApp.cpp)

target_link_libraries(${PROJECT_NAME} TicTacToe_Core)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_include_directories(${PROJECT_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
