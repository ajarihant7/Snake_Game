#include "./myHeaders/myHeaders.h"

void gotoXY(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(consle,c);
}