#include "./myHeaders/myHeaders.h"

void gameSetup(){
    consle = GetStdHandle(STD_OUTPUT_HANDLE);
    gameOver=false;
    dir=Stop;
    current_x = Window_width/2;
    current_y = Window_height/2;
    fruit_x = rand()%Window_width;
    fruit_y = rand()%Window_height;
    score = 0;
}