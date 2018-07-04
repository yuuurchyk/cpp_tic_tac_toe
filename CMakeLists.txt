cmake_minimum_required(VERSION 3.5)
project(tic_tac_toe)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(
    Exceptions
    Field
    Tokens
    FieldTree
    Player
    Select
    Text
    Gui
    Controller
    Game
)

file(
    GLOB SOURCES
    "Exceptions/*.cpp"
    "Field/*.cpp"
    "Tokens/*.cpp"
    "FieldTree/*.cpp"
    "Player/*.cpp"
    "Select/*.cpp"
    "Text/*.cpp"
    "Gui/*.cpp"
    "Controller/*.cpp"
    "Game/*.cpp"
    main.cpp
)

add_executable(tic_tac_toe ${SOURCES})
target_link_libraries(tic_tac_toe ${CURSES_LIBRARIES})
