#pragma once

#include <Windows.h>

class Snake
{
public:
    Snake(COORD pos, int vel);

    void change_direction(char dir);

    void move_snake();

    COORD get_pos();

    bool eaten(COORD food_pos);

    void grow();

private:
    COORD position;
    int len;
    int vel;
    char direction;
};
