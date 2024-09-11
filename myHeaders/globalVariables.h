#include<windows.h>
#pragma once
enum Direction { Stop=0, Right, Left, Up, Down };
extern Direction dir;

extern HANDLE consle; // handle cursor control


extern int current_x, current_y; //snake's head postion
extern int score;//keeping track of score collected
extern const int Window_height; // changed to 20 from 30
extern const int Window_width;// changed to 20 from 30
extern int fruit_x,fruit_y; // fruits current postion

extern int tail_x[100], tail_y[100];
extern int tail_len;
extern bool gameOver;