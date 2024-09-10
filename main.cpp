#include<iostream>
#include<conio.h>
#include<windows.h>


enum Direction { Stop=0, Right, Left, Up, Down };

int current_x, current_y; //snake's head postion
int score=0; //keeping track of score collected
const int Window_height=20; // changed to 20 from 30
const int Window_width=20; // changed to 20 from 30
int fruit_x,fruit_y; // fruits current postion
Direction dir; // current direction update 

int tail_x[100], tail_y[100];
int tail_len;
HANDLE consle; // handle cursor control

bool gameOver;

void gotoXY(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(consle,c);
}

void Box(){
    gotoXY(0,0);
    for(int i=0;i<Window_width+2;i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;
    for(int i=0;i<Window_height;i++){
        for(int j=0;j<Window_width;j++){
            if(j==0){
                std::cout<<"#";
            }
            if(i==current_y && j==current_x){
                std::cout<<"O"; //snake's head
            }
            else if(i==fruit_y && j==fruit_x){
                std::cout<<"1"; //fruit denoted with score the snake will get once collected
            }
            else{
                bool tail=false;
                for(int k=0;k<tail_len;k++){
                    if(tail_x[k]==j && tail_y[k]==i){
                        std::cout<<"0";
                        tail=true;
                    }
                }
                if(tail==false){
                    std::cout<<" ";
                }
            }
            if(j==Window_width-1){
                std::cout<<"#";
            }
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<Window_width+2;i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;
    std::cout<<"Fruits Collected: "<<score<<std::endl;
}

void KeyBoard_IP(){
    if(_kbhit()){
        switch (_getch()){
        case 'a':
            dir=Left;
            break;
        case 'w':
            dir=Up;
            break;
        case 'd':
            dir=Right;
            break;
        case 's':
            dir=Down;
            break;
        case 'x':
            gameOver=true;
            break;
        }
    }
}

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

int main(){
    gameSetup();
    while(!gameOver){
        Box();
        KeyBoard_IP();
        gameLogic();
        Sleep(100);
    }
    
    return 0;
}


