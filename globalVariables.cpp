#include "./myHeaders/globalVariables.h"


Direction dir;

HANDLE consle; // handle cursor control


int current_x=0, current_y=0; //snake's head postion

int fruit_x=3,fruit_y=3; // fruits current postion

int tail_x[100], tail_y[100];
int tail_len=0;




int score=0; //keeping track of score collected
const int Window_height=20; // changed to 20 from 30
const int Window_width=20; // changed to 20 from 30
bool gameOver = false;

