#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->position = pos;
    this->vel = vel;

    len = 1;
    direction = 'n';

    body.push_back(pos);
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

    body.push_back(position);
    if (body.size() > len)
    {
        body.erase(body.begin());
    }
}

COORD Snake::get_pos()
{
    return position;
}


bool Snake::collide()
{
    if (position.X < 1 || position.X > WIDTH - 2 || position.Y < 1 || position.Y > HEIGHT - 2)
    {
      return true;
    }
    else 
    {
      return false;
    }
      
}

bool Snake::eaten(COORD food_pos)
{
    if(food_pos.X == position.X && food_pos.Y == position.Y)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Snake::grow()
{
    len++;
}

vector<COORD> Snake::get_body()
{
    return body;
}


