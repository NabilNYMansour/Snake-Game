#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#include "helpers.h"

int makeScreen(char screen[SIZE_X][SIZE_Y])
{
    int food = 0;
    for (int i = 0; i < SIZE_X; ++i)
    {
        for (int j = 0; j < SIZE_Y; ++j)
        {
            if (i == 0 || i == SIZE_X - 1 || j == 0 || j == SIZE_Y - 1)
            {
                screen[i][j] = '#';
            }
            else
            {
                if (rand() % 17 == 0)
                {
                    screen[i][j] = 'Q';
                    ++food;
                }
                else
                {
                    screen[i][j] = '\0';
                }
            }
        }
    }
    return food;
}

void printScreen(char screen[SIZE_X][SIZE_Y])
{
    for (int i = 0; i < SIZE_X; ++i)
    {
        for (int j = 0; j < SIZE_Y; ++j)
        {
            putchar(screen[i][j]);
            putchar('\0');
        }
        putchar('\n');
    }
}
