#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

class Board
{
public:
	void draw_board();
	void set_board_dimensions();
	COORD get_board_dimensions();
private:
	COORD board_dimensions;
};

