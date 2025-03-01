#pragma once
#include "colors.hpp"


// For parser
#define START_OUTPUT "> "
#define INCORRECT_OUTPUT "BAN"

// For point
#define START_BASIC_X 0
#define START_BASIC_Y 0

// For window
#define START_BASIC_X_COORDINATE 0
#define START_BASIC_Y_COORDINATE 0
#define START_BASIC_WIDTH_WINDOW 10
#define START_BASIC_HEIGHT_WINDOW 10

// For handlers
#define ARGUMENT_START_VALUE "BAN"

// For windows manager
#define ADD "add"
#define LIST "list"
#define MOVE "move"
#define CLICK "click"
#define DEL "del"
#define CHANGE_COL "change_col"
#define CHANGE_BORDER_COL "change_border_col"
#define OPEN "open"
#define CLOSE "close"

// background colors
#define BLACK_BACKGROUND "\e[40m"
#define RED_BACKGROUND "\e[41m"
#define GREEN_BACKGROUND "\e[42m"
#define YELLOW_BACKGROUND "\e[43m"
#define BLUE_BACKGROUND "\e[44m"
#define PURPLE_BACKGROUND "\e[45m"
#define CYAN_BACKGROUND "\e[46m"
#define WHITE_BACKGROUND "\e[47m"

#define BLACK "black"
#define RED "red"
#define GREEN "green"
#define YELLOW "yellow"
#define BLUE "blue"
#define PURPLE "purple"
#define CYAN "cyan"
#define WHITE "white"

#define BOUNDARY_SYMBOL '#'
#define EMPTY_CONSOLE "\033[2J\033[1;1H"

#define ARGUMENT_ERROR "Argument error"
#define EMPTY_WINDOWS_ERROR "Window manager does not have windows"
#define SIZE_ERROR "Size error"
