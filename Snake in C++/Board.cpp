#include "Board.h"

void Board::draw_board()
{
    for (int i = 0; i <= board_dimensions.Y; i++)
    {
        for (int j = 0; j <= board_dimensions.X; j++)
        {
            if (i == 0 || i == board_dimensions.Y)
            {
                std::cout << "-";
            }
            else if (j == 0 || j == board_dimensions.X)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::set_board_dimensions()
{
    int option;
    std::cout << "Choose board size: " <<std::endl;
    std::cout << "1. 41x15" << std::endl;
    std::cout << "2. 61x21" << std::endl;
    std::cin >> option;
    switch (option)
    {
    case 1:
        board_dimensions.X = 41;
        board_dimensions.Y = 15;
        break;
    case 2:
        board_dimensions.X = 61;
        board_dimensions.Y = 21;
        break;
    }
    std::system("CLS");
}

COORD Board::get_board_dimensions()
{
	return board_dimensions;
}
