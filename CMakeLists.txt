cmake_minimum_required(VERSION 3.5)
project(tic_tac_toe)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")

include_directories(
    Common
    Exceptions
    Field
    FieldTree
    Game
    Player
    PlayerFactory
    Read
    Tokens
)

file(
    GLOB SOURCES
    "Common/*.cpp"
    "Exceptions/*.cpp"
    "Field/*.cpp"
    "FieldTree/*.cpp"
    "Game/*.cpp"
    "Player/*.cpp"
    "PlayerFactory/*.cpp"
    "Read/*.cpp"
    "Tokens/*.cpp"
    main.cpp
)

add_executable(tic_tac_toe ${SOURCES})