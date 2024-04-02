#include<iostream>
#include"Board.h"
#include"Snake.h"
#include"Engine.h"
#include"Fruit.h"

int main()
{
	Board board;
	Snake snake;
	Fruit fruit;
	Engine engine;
	engine.set_speed();
	board.set_board_dimensions();
	board.draw_board();
	snake.create_snake(board);
	fruit.first_fruit_location(board);
	engine.run(snake, board, fruit);
	return 0;
}