#pragma once

#include <Windows.h>
#include <cstdlib>

#define WIDTH 50
#define HEIGHT 25

class Food
{
public:
    Food();

    void gen_food();

    COORD get_pos();
private:
    COORD position;
};
