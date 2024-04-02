#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include "Snake.h"
#include "Board.h"
#include "Fruit.h"

class Engine
{
public:
    void run(Snake snake, Board board, Fruit fruit);
    void print(char character, COORD location);
    bool colision(bool action, COORD head, COORD board_dimensions);
    char get_direction(char direction);
    void set_speed();
private:
    int speed;
    int level = 0;
    bool action = true;
    bool is_ate_fruit = false;
    char direction = 'd';
    COORD head;
    COORD nail;
    COORD fruit_location;
    COORD board_dimensions;
};

