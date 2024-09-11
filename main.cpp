#include "./myHeaders/myHeaders.h"


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


