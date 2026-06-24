cmake_minimum_required(VERSION 3.6)

project(tictactoe-tui VERSION 0.1 LANGUAGES CXX)


add_executable(tictactoe-tui
    main.cc 
    Game.cc 
    Player.cc
    Board.cc 
    Symbol.cc 
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

