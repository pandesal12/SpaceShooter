#include <conio.h>


namespace shooter {
    char getInput() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }
}