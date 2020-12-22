#ifndef HELPERS_H
#define HELPERS_H

#define SIZE_X 20
#define SIZE_Y 80

typedef struct bodyPart
{
    int x;
    int y;
} bodyPart;

typedef struct snake
{
    bodyPart body[50];
} snake;

void printScreen(char screen[SIZE_X][SIZE_Y]);
int makeScreen(char screen[SIZE_X][SIZE_Y]);
#endif