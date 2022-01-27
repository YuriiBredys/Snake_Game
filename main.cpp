#include <iostream>
#include <conio.h>

#include "Snake_Files/Snake.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH / 2,HEIGHT / 2 }, 1);

void board()
{
    COORD snake_pos = snake.get_pos();

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";

        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
            {
                cout << '#';
            }
            else if(i == snake_pos.Y && j == snake_pos.X)
            {
                cout << "S";
            }
            else
            {
                cout << ' ';
            }

        }

        cout << '#' << endl;
    }
}

int main()
{
    while (true)
    {
        board();

        if(_kbhit())
        {
            switch (_getch())
            {
            case 'w': 
                snake.change_direction('u');
                break;
            case 's':
                snake.change_direction('d');
                break;
            case 'a':
                snake.change_direction('l');
                break;
            case 'd':
                snake.change_direction('r');
                break;
            }   
        }

        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

    return 0;
}