#pragma once

#include <Windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

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

    vector<COORD> get_body();

private:
    vector<COORD> body;
    COORD position;
    int len;
    int vel;
    char direction;
};
