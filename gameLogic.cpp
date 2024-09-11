#include "./myHeaders/myHeaders.h"


void gameLogic(){
    int X = tail_x[0];
    int Y = tail_y[0];
    int a,b;
    tail_x[0] = current_x;
    tail_y[0] = current_y;
    for(int i=1;i<tail_len;i++){
        a = tail_x[i];
        b = tail_y[i];
        tail_x[i] = X;
        tail_y[i] = Y;
        X = a;
        Y = b;
    }
    switch(dir){
        case Up:
            current_y--;
            break;
        case Right:
            current_x++;
            break;
        case Down:
            current_y++;
            break;
        case Left:
            current_x--;
            break;
        default:
            break;
    }
    if(current_x<0){
        current_x = Window_width-1;
    }
    if(current_x>=Window_width){
        current_x = 0;
    }
    if(current_y<0){
        current_y = Window_height-1;
    }
    if(current_y>=Window_height){
        current_y = 0;
    }
    for(int i=0;i<tail_len;i++){
        if(tail_x[i]==current_x && tail_y[i]==current_y){
            gameOver = true;
        }
    }
    if(current_x == fruit_x && current_y == fruit_y){
        score+=1;
        fruit_x = rand()%Window_width;
        fruit_y = rand()%Window_height;
        tail_len+=1;
    }
}