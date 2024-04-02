#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Snake.h"
#include "Board.h"


class Fruit
{
public:
	void first_fruit_location(Board board);
	COORD get_location();
	COORD set_fruit(Board board);
private:
	COORD fruit;
};

