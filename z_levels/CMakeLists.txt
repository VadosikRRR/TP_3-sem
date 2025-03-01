cmake_minimum_required(VERSION 3.5)

project(z_levels_project)

set(SOURCE_EXE main.cpp)

set(PATH_TO_CPP_FILES src)

set(SOURCE_LIB_WINDOWS_MANAGER ${PATH_TO_CPP_FILES}/windows_manager.cpp)
set(SOURCE_LIB_PARSER ${PATH_TO_CPP_FILES}/parser.cpp)
set(SOURCE_LIB_WINDOW ${PATH_TO_CPP_FILES}/window.cpp)
set(SOURCE_LIB_HANDLERS ${PATH_TO_CPP_FILES}/handlers.cpp)
set(SOURCE_LIB_POINT ${PATH_TO_CPP_FILES}/point.cpp)

add_library(windows_manager STATIC ${SOURCE_LIB_WINDOWS_MANAGER})
add_library(parser STATIC ${SOURCE_LIB_PARSER})
add_library(handlers STATIC ${SOURCE_LIB_HANDLERS})
add_library(window STATIC ${SOURCE_LIB_WINDOW})
add_library(point STATIC ${SOURCE_LIB_POINT})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main windows_manager parser window handlers point)