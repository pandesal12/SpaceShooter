#include <iostream>
#include <windows.h>
#include <vector>
#include "Header.h"

using namespace std;

namespace renderer {
    static void setCursorPosition(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    static vector<string> CreateBorder() {
        vector<string> border(29);
        for (int i = 0; i < 29; i++) {
            border[i] = "";
            for (int j = 0; j < 52; j++) {
                if (i == 0)
                    border[i] += (j == 0 ? '#' : (j == 51 ? '#' : '-'));
                else if (i == 28)
                    border[i] += (j == 0 ? '#' : (j == 51 ? '#' : '-'));
                else
                    border[i] += (j == 0 || j == 51 ? '|' : ' ');
            }
        }
        return border;
    }

    vector<string> border = CreateBorder();

    void Update() {
        setCursorPosition(0, 0);
        for (const auto& line : border)
            cout << line << endl;

        for (const auto& obj : logic::GetList()) {
            for (int j = 0; j < obj.sprite.size(); j++) {
                int posY = obj.y + j;
                if (posY > 0 && posY < 28) {
                    setCursorPosition(obj.x, posY);
                    cout << obj.sprite[j];
                }
            }
        }
        Sleep(20);
    }
}