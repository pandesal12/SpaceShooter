#include <iostream>
#include <conio.h>  
#include <windows.h> 
#include <array>

using namespace std;

string options[] = { "Start Game", "Members", "Exit" };
const int numOptions = sizeof(options) / sizeof(options[0]);

int main();

void Exit() {
    exit(0);
}

void DisplayMenu(int selected) {
    system("cls"); 

    cout << "=== MAIN MENU ===\n\n";
    for (int i = 0; i < numOptions; i++) {
        if (i == selected)
            cout << " > "; 
        else
            cout << "   ";

        cout << options[i] << endl;
    }
    cout << "\n=== ==== ==== ===\n\n";
}

void DisplayMembers() {
    cout << "=== Members ===\n\n";
    cout << "Arvin Miguel Antonio" << endl;
    cout << "Francis Homer Infante" << endl;
    cout << "Angelo Justine Kamachi" << endl;
    cout << "John Aldrine Lim\n\n" << endl;
    
    cout << "> Back " << endl;
    cout << "\n=== ==== ==== ===\n\n";

    char key = 0;
    while (key != 13) {
        char key = _getch();
        if (key == 13) {
            system("cls");
            main();
        }
    }
}

class PlayerShip {
public:
    array<int, 2> position = { 0, 0 };
    int hp = 100;
    string sprite = 
    ">=>     \n"
    ">=XX0X=>\n"
    ">=>     ";
};

class Asteroid {
public:
    array<int, 2> position = { 0, 0 };
    string sprite =
        "/0\\\n"
        "|-|\n"
        "\\0/";
};

void RunGame() {
    
}

int menu() {
    int selected = 0;
    char key;


    while (true) {
        DisplayMenu(selected);
        key = _getch(); 
        void (*funcArray[])() = { DisplayMembers, DisplayMembers, Exit };

        if (key == 72) {
            selected = (selected - 1 + numOptions) % numOptions;
        } else if (key == 80) {
            selected = (selected + 1) % numOptions;
        } else if (key == 13) { 
            system("cls");
            funcArray[selected]();
            break;
        }
    }

    return 0;
}
