#include "Fruit.h"

COORD Fruit::set_fruit(Board board)
{
	COORD fruit_position;
	COORD board_dimensions;
	board_dimensions = board.get_board_dimensions();
	srand(time(NULL));
	fruit_position.X = rand() % (board_dimensions.X - 2) + 1;
	fruit_position.Y = rand() % (board_dimensions.Y - 2) + 1;
	return fruit_position;
}

void Fruit::first_fruit_location(Board board)
{
	COORD fruit_location;
	fruit_location = board.get_board_dimensions();
	fruit_location.X = (fruit_location.X) / 2 + 1;
	fruit_location.Y = (fruit_location.Y) / 2 + 1;
	fruit = fruit_location;
}

COORD Fruit::get_location()
{
	return fruit;
}