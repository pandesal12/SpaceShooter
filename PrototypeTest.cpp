#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Header.h"

using namespace std;


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
    logic::AddObj(22, 18, ship);

    vector<string> asteroid = {
        " ,~.~.~,  ",
        "/ . O :.\\ ",
        ": o .  : |",
        ":,. . o:.,",
        " ',._,_,' "
    };
    logic::AddObj(1, -10, asteroid);
    logic::AddObj(41, -15, asteroid);
    logic::AddObj(12, -15, asteroid);
    logic::AddObj(32, -15, asteroid);

    while (true) {
        logic::Update();
        renderer::Update();
    }
    return 0;
}
