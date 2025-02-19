cmake_minimum_required(VERSION 3.5)

project(text_editor_project)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB_DOCUMENT document.cpp)

set(SOURCE_LIB_TEXT_EDITOR text_editor.cpp)

set(SOURCE_LIB_PARSER parser.cpp)

set(SOURCE_LIB_MANAGER manager.cpp)

set(SOURCE_LIB_HANDLER handler_coomand_arguments.cpp)

set(SOURCE_LIB_COMMAND editor_commands.cpp)

set(SOURCE_LIB_PRINTER printer.cpp)

add_library(printer STATIC ${SOURCE_LIB_PRINTER})

add_library(editor_commands STATIC ${SOURCE_LIB_COMMAND})

add_library(handler_coomand_arguments STATIC ${SOURCE_LIB_HANDLER})

add_library(manager STATIC ${SOURCE_LIB_MANAGER})

add_library(parser STATIC ${SOURCE_LIB_PARSER})

add_library(document STATIC ${SOURCE_LIB_DOCUMENT})

add_library(text_editor STATIC ${SOURCE_LIB_TEXT_EDITOR})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main text_editor document parser manager handler_coomand_arguments editor_commands printer)