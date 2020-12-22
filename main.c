#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

#include "helpers.h"

int main()
{
    printf("\n\n\t\tSNAKE GAME!\n\t\tMade by Nabil NY Mansour.");
    Sleep(4000);
    srand(time(NULL));

    system("MODE 1000");

    char screen[SIZE_X][SIZE_Y];
    int food = makeScreen(screen);

    double score = 0;

    snake player;
    player.body[food];
    player.body[0].x = SIZE_X / 2;
    player.body[0].y = SIZE_Y / 2;

    int count = 1;

    screen[player.body[0].x][player.body[0].y] = 'X';

    system("cls");
    printScreen(screen);
    printf("Score: %f| Food left: %d| size: %d\nUse wasd + <enter> to move\nInput: ", score, food, count);

    char userInput;
    int stepsTaken = 1;
    bodyPart head;

    head = player.body[0];
    while (food != 0)
    {
        userInput = getchar();
        if (userInput == 'w' || userInput == 's' || userInput == 'a' || userInput == 'd')
        {
            if (userInput == 'w' || userInput == 'W')
            {
                if (player.body[0].x != 1)
                {
                    if (screen[player.body[0].x - 1][player.body[0].y] == 'Q')
                    {
                        --food;
                        score += 1.0 / stepsTaken;
                        stepsTaken = 1;
                        ++count;
                    }
                    else if (screen[player.body[0].x - 1][player.body[0].y] == 'O')
                    {
                        printf("YOU LOSE\n");
                        return 0;
                    }
                    else
                    {
                        ++stepsTaken;
                    }
                    --head.x;
                }
                else
                {
                    continue;
                }
            }

            else if (userInput == 's' || userInput == 'S')
            {
                if (player.body[0].x != SIZE_X - 2)
                {
                    if (screen[player.body[0].x + 1][player.body[0].y] == 'Q')
                    {
                        --food;
                        score += 1.0 / stepsTaken;
                        stepsTaken = 1;
                        ++count;
                    }
                    else if (screen[player.body[0].x + 1][player.body[0].y] == 'O')
                    {
                        printf("YOU LOSE\n");
                        return 0;
                    }
                    else
                    {
                        ++stepsTaken;
                    }
                    ++head.x;
                }
                else
                {
                    continue;
                }
            }

            else if (userInput == 'a' || userInput == 'A')
            {
                if (player.body[0].y != 1)
                {
                    if (screen[player.body[0].x][player.body[0].y - 1] == 'Q')
                    {
                        --food;
                        score += 1.0 / stepsTaken;
                        stepsTaken = 1;
                        ++count;
                    }
                    else if (screen[player.body[0].x][player.body[0].y - 1] == 'O')
                    {
                        printf("YOU LOSE\n");
                        return 0;
                    }
                    else
                    {
                        ++stepsTaken;
                    }
                    --head.y;
                }
                else
                {
                    continue;
                }
            }

            else if (userInput == 'd' || userInput == 'D')
            {
                if (player.body[0].y != SIZE_Y - 2)
                {
                    if (screen[player.body[0].x][player.body[0].y + 1] == 'Q')
                    {
                        --food;
                        score += 1.0 / stepsTaken;
                        stepsTaken = 1;
                        ++count;
                    }
                    else if (screen[player.body[0].x][player.body[0].y + 1] == 'O')
                    {
                        printf("YOU LOSE\n");
                        return 0;
                    }
                    else
                    {
                        ++stepsTaken;
                    }
                    ++head.y;
                }
                else
                {
                    continue;
                }
            }

            for (int i = count; i >= 0; --i)
            {
                if (i == 0)
                {
                    player.body[0] = head;
                    screen[player.body[i].x][player.body[i].y] = userInput;
                }
                else
                {
                    player.body[i] = player.body[i - 1];
                    screen[player.body[i].x][player.body[i].y] = 'O';
                }
            }
            if (count != 0)
            {
                screen[player.body[count].x][player.body[count].y] = '\0';
            }
            system("cls");
            printScreen(screen);
            printf("Score: %f| food left: %d| size: %d\nInput: ", score, food, count);
        }
        else if (userInput == 'q' || userInput == 'Q')
        {
            printf("Exitting");
            Sleep(500);
            putchar('.');
            Sleep(500);
            putchar('.');
            Sleep(500);
            putchar('.');
            Sleep(1000);
            return 0;
        }
    }
    printf("YOU WIN\nPress any key... ");
    if (getchar() == '\n');
    getchar();
    return 0;
}
