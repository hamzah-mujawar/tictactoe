cmake_minimum_required(VERSION 3.16)

project(TicTacToe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(tictactoe-gui
    main.cc
)

qt_add_qml_module(tictactoe-gui
    URI TicTacToe
    VERSION 1.0
    QML_FILES Main.qml 
    SOURCES Game.cc Game.h Board.cc Board.h Player.cc Player.h Symbol.cc Symbol.h
)

set_target_properties(tictactoe-gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(tictactoe-gui
    PRIVATE Qt6::Quick)

install(TARGETS tictactoe-gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
