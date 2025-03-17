#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

namespace logic {
    char GetInput() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }
    struct ScreenObject {
        int x, y;
        int edgeX, edgeY;
        vector<string> sprite;
        static vector<ScreenObject> objList;
    };
    vector<ScreenObject> objList;
    const vector<ScreenObject>& GetList() {
        return objList;
    }
    static void AddObj(int x, int y, vector<string> sprite) {
        ScreenObject obj;
        obj.x = x;
        obj.y = y;
        obj.edgeX = sprite[0].length();
        obj.edgeY = sprite.size();
        obj.sprite = sprite;
        ScreenObject::objList.push_back(obj);
    }

    double timer = 0;
    void Update() {
        ScreenObject& ship = ScreenObject::objList[0];
        char key = GetInput();
        if (key == 'a' || key == 75) {
            if (ship.x > 1) ship.x -= 1;
        }
        else if (key == 'd' || key == 77) {
            if (ship.x + ship.edgeX < 51) ship.x += 1;
        }
        int arr[] = { 1, 12, 22, 32, 41 };
        for (size_t i = 1; i < ScreenObject::objList.size(); i++) {
            ScreenObject& ast = ScreenObject::objList[i];
            if (timer > 1 && ast.y < 28) {
                ast.y++;
                timer = 0;
            }
            else if (ast.y > 27) {
                ast.y = -10;
                ast.x = arr[rand() % 5];
            }
            timer += 0.10;
        }
    }
}