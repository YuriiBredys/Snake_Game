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
int score;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    vector<COORD> snake_body = snake.get_body();

    cout << "SCORE : " << score << endl << endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";

        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
            {
                cout << '#';
            }
            else if(i == snake_pos.Y && j + 1 == snake_pos.X)
            {
                cout << 'S';
            }
            else if(i == food_pos.Y && j + 1 == food_pos.X)
            {
                cout << '@';
            }
            else
            {
                bool is_body_part = false;

                for (int k = 0; k < snake_body.size() - 1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        is_body_part = true;
                        break;
                    }
                }

                if(!is_body_part)
                {
                    cout << ' ';
                }
            }

        }

        cout << '#' << endl;
    }
}

int main()
{
    score = 0;

    bool game_over = false;

    srand(time(NULL));
  
    while (!game_over)
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

        if (snake.collide())
        {
            game_over = true;
        }
      
        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score += 10;
        }

        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

    return 0;
}