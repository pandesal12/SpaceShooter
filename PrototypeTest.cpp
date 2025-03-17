#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ScreenObject {
    int x, y;
    int edgeX, edgeY;
    vector<string> sprite;
    static vector<ScreenObject> objList;
};

vector<ScreenObject> ScreenObject::objList;

void addObj(int x, int y, vector<string> sprite) {
    ScreenObject obj;
    obj.x = x;
    obj.y = y;
    obj.edgeX = sprite[0].length();
    obj.edgeY = sprite.size();
    obj.sprite = sprite;
    ScreenObject::objList.push_back(obj);
}

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

vector<string> createBorder() {
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

vector<string> border = createBorder();

void updateFrame() {
    setCursorPosition(0, 0);
    for (const auto& line : border)
        cout << line << endl;

    for (const auto& obj : ScreenObject::objList) {
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

char getInput() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}

double timer = 0;
void logic() {
    ScreenObject& ship = ScreenObject::objList[0];
    char key = getInput();
    if (key == 'a' || key == 75) {
        if (ship.x > 1) ship.x -= 1;
    } else if (key == 'd' || key == 77) {
        if (ship.x + ship.edgeX < 51) ship.x += 1;
    }
    int arr[] = { 1, 12, 22, 32, 41 };
    for (size_t i = 1; i < ScreenObject::objList.size(); i++) {
        ScreenObject& ast = ScreenObject::objList[i];
        if (timer > 1 && ast.y < 28) {
            ast.y++;
            timer = 0;
        } else if (ast.y > 27) {
            ast.y = -10;
            ast.x = arr[rand() % 5];
        }
        timer += 0.10;
    }
}

int main() {
    srand(time(0));
    vector<string> ship = {
        "     |     ",
        "    /:\\    ",
        "   |( )|   ",
        "   |   |   ",
        "   |   |   ",
        "  /|   |\\  ",
        " / |   | \\",
        "<__|   |__>",
        "   <TTT>   ",
        "  /^\\ /^\\  "
    };
    addObj(22, 18, ship);

    vector<string> asteroid = {
        " ,~.~.~,  ",
        "/ . O :.\\ ",
        ": o .  : |",
        ":,. . o:.,",
        " ',._,_,' "
    };
    addObj(1, -10, asteroid);
    addObj(41, -15, asteroid);
    addObj(12, -15, asteroid);
    addObj(32, -15, asteroid);

    while (true) {
        logic();
        updateFrame();
    }
    return 0;
}
