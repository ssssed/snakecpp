#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y, xPoint, yPoint, score = 0;
enum eDirection
{
    stop = 0,
    Left,
    Right,
    Top,
    Bottom
};
eDirection dir;

void setUp()
{
    gameOver = false;
    dir = stop;
    x = width / 2;
    y = height / 2;
    xPoint = rand() % width;
    yPoint = rand() % height;
}

void map()
{
    system("cls");

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }

            if (i == y && j == x)
            {
                cout << "*";
            }

            else if (i == yPoint && j == xPoint)
            {
                cout << "@";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
    printf("Score: %i\n", score);
}

void control()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 72:
            dir = Top;
            break;
        case 80:
            dir = Bottom;
            break;
        case 75:
            dir = Left;
            break;
        case 77:
            dir = Right;
            break;
        case 's':
            gameOver = true;
            break
        }
    }
}

void rulse()
{
    if (x == xPoint && y == yPoint)
    {
        score++;
        xPoint = rand() % width;
        yPoint = rand() % height;
    }

    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }
}

int main()
{
    setUp();
    while (!gameOver)
    {
        map();
        control();
        rulse();
    }
    return 0;
}