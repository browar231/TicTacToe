cmake_minimum_required(VERSION 3.0.0)
project(TicTacToe VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED)

set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/Board.cpp ${PROJECT_SOURCE_DIR}/src/Console.cpp ${PROJECT_SOURCE_DIR}/src/Player.cpp ${PROJECT_SOURCE_DIR}/src/PlayerCPU.cpp ${PROJECT_SOURCE_DIR}/src/TicTacToe.cpp)

if(WIN32)
    add_executable(${PROJECT_NAME}_ConsoleApp WIN32 ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/ConsoleApp.cpp ${PROJECT_SOURCE_DIR}/src/PlayerConsole.cpp)
endif()
if(UNIX)
    add_executable(${PROJECT_NAME}_ConsoleApp ${SOURCE_FILES} ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/ConsoleApp.cpp ${PROJECT_SOURCE_DIR}/src/PlayerConsole.cpp)
    # add_executable(${PROJECT_NAME}_App ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/TicTacToeConsoleApp.cpp ${SOURCE_FILES})
endif()
target_include_directories(${PROJECT_NAME}_ConsoleApp
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/inc
)
