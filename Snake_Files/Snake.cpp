#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->position = pos;
    this->vel = vel;

    len = 1;
    direction = 'n';
}

void Snake::change_direction(char dir)
{
    direction = dir;
}

void Snake::move_snake()
{
    switch (direction)
    {
        case 'u': 
            position.Y -= vel;
            break;
        case 'd':
            position.Y += vel;
            break;
        case 'l':
            position.X -= vel;
            break;
        case 'r':
            position.X += vel;
            break;
    }
}

COORD Snake::get_pos()
{
    return position;
}

bool Snake::collide()
{
    if (position.X < 1 || position.X > WIDTH || position.Y < 1 || position.Y > HEIGHT)
    {
        return true;
    }
    else
    {
        return false;
    }
}


