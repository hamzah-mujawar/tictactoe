cmake_minimum_required(VERSION 3.6)

project(TicTacToeTUI VERSION 0.1 LANGUAGES CXX)


add_executable(TicTacToeTUI
    main.cc 
    Game.cc 
    Player.cc
    Board.cc 
    Symbol.cc 
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

