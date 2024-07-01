#include <windows.h>
#include <iostream>
#include <ctime>

std::string GetActiveWindowTitle()
{
    char win_title[256];
    HWND hwnd = GetForegroundWindow();
    if (hwnd == nullptr) return "No Active Window";

    GetWindowTextA(hwnd, win_title, sizeof(win_title));
    return std::string(win_title);
}

int main()
{
    time_t start, finish; // variables for time difference
    char window_buf[256]; // used to store current window title
    while(true)
    {
        std::string(window_buf) = GetActiveWindowTitle();
        
        std::cout << "Active window: " + GetActiveWindowTitle() << std::endl;
        Sleep(60000); // wait 60 seconds
    }

    return 0;
}