#pragma once
#include <iostream>
#include <Windows.h>
#include <deque>
#include "Board.h"

class Snake
{
public:
	bool is_dead(bool action);
	void create_snake(Board board);
	void move_snake(COORD head,bool is_ate_fruit);
	void add_segment(COORD nail);
	COORD get_head();
	COORD get_nail();
private:
	std::deque<COORD>snake_body;
};
