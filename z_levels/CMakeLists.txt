cmake_minimum_required(VERSION 3.5)

project(z_levels_project)

set(SOURCE_EXE main.cpp)

set(PATH_TO_CPP_FILES src)

set(SOURCE_LIB_WINDOWS_MANAGER ${PATH_TO_CPP_FILES}/windows_manager.cpp)
set(SOURCE_LIB_PARSER ${PATH_TO_CPP_FILES}/parser.cpp)

add_library(windows_manager STATIC ${SOURCE_LIB_WINDOWS_MANAGER})
add_library(parser STATIC ${SOURCE_LIB_PARSER})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main windows_manager parser)