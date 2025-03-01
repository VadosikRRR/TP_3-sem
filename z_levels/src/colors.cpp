#include "include/constants.hpp"
#include "include/colors.hpp"

std::unordered_map<std::string, std::string> COLORS;

void fill_colors() {
    COLORS[BLACK] = BLACK_BACKGROUND;
    COLORS[RED] = RED_BACKGROUND;
    COLORS[GREEN] = GREEN_BACKGROUND;
    COLORS[YELLOW] = YELLOW_BACKGROUND;
    COLORS[BLUE] = BLUE_BACKGROUND;
}