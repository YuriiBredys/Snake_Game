#pragma once

#include <Windows.h>

#define WIDTH 50
#define HEIGHT 25

class Snake
{
public:
    Snake(COORD pos, int vel);

    void change_direction(char dir);

    void move_snake();

    COORD get_pos();

    bool collide();

    bool eaten(COORD food_pos);

    void grow();

private:
    COORD position;
    int len;
    int vel;
    char direction;
};
