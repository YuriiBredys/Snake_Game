#pragma once

#include <Windows.h>
#include <cstdlib>

class Food
{
public:
    Food();

    void gen_food();

    COORD get_pos();
private:
    COORD position;
};
