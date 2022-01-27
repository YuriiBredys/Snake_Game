#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake_Files/Snake.h"
#include "Food_Files/Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH / 2,HEIGHT / 2 }, 1);
Food food;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

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
                cout << 'S';
            }
            else if(i == food_pos.Y && j == food_pos.X)
            {
                cout << '@';
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
    srand(time(NULL));

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

        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

    return 0;
}