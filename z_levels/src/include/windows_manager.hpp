#pragma once
#include <memory>


class WindowsManager {
private:
    static std::unique_ptr<WindowsManager> _instance;
    // void StringProcessing(std::string command_text);
protected:
    WindowsManager();
public:
    static WindowsManager & Instance();
    void Launch();
};
