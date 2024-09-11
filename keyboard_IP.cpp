#include "./myHeaders/myHeaders.h"




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