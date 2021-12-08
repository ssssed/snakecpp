#include <stdio.h>
#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, xPoint, yPoint;
enum eDirection
{
    stop = 0,
    Left,
    Rgith,
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
    system("clear");

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
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
    {
        cout << "#";
    }
    cout << endl;
}

void control()
{
}

void rulse()
{
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