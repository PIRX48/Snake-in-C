#include "Snake.h"

bool Snake::is_dead(bool action)
{
	for (size_t i = 1; i < snake_body.size(); i++)
	{
		if (snake_body[0].X == snake_body[i].X && snake_body[0].Y == snake_body[i].Y)
		{
			action = false;
		}
	}
	return action;
}

void Snake::create_snake(Board board)
{
	COORD location;
	location = board.get_board_dimensions();
	location.X = (location.X) / 2 + 1;
	location.Y = (location.Y) / 2 + 1;
	snake_body.push_back(location);
	location.X = (location.X) / 2 + 0;
	snake_body.push_back(location);
	location.Y = (location.Y) / 2 - 1;
	snake_body.push_back(location);

}

void Snake::move_snake(COORD head, bool is_ate_fruit)
{
	snake_body.push_front(head);
	if (is_ate_fruit == false)
	{
		snake_body.pop_back();
	}
}

void Snake::add_segment(COORD nail)
{
	snake_body.push_back(nail);
}

COORD Snake:: get_head()
{
	return snake_body.front();
}

COORD Snake::get_nail()
{
	return snake_body.back();
}

