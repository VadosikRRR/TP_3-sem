#include "src/include/windows_manager.hpp"


int main() {
    WindowsManager & windows_manager = WindowsManager::Instance();
    windows_manager.SetWidth(60);
    windows_manager.Setheight(30);
    windows_manager.Launch();
    return 0;
}