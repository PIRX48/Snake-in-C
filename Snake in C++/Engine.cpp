#include "Engine.h"

void Engine::run(Snake snake, Board board, Fruit fruit)
{
    board_dimensions = board.get_board_dimensions();
    fruit_location = fruit.get_location();
    while (action)
    {
        head = snake.get_head();
        print('S', head);
        Sleep(speed);
        nail = snake.get_nail();
        print(' ', nail);
        action = snake.is_dead(action);
        direction = get_direction(direction);
        if (head.X == fruit_location.X && head.Y == fruit_location.Y)
        {
            is_ate_fruit = true;
            level++;
            fruit_location = fruit.set_fruit(board);
            print('F', fruit_location);
        }
        switch (direction)
        {
        case 'w':
            head.Y--;
            snake.move_snake(head, is_ate_fruit);
            break;
        case 's':
            head.Y++;
            snake.move_snake(head, is_ate_fruit);
            break;
        case 'a':
            head.X--;
            snake.move_snake(head, is_ate_fruit);
            break;
        case 'd':
            head.X++;
            snake.move_snake(head, is_ate_fruit);
            break;
        }
        is_ate_fruit = false;
        action = colision(action, head, board_dimensions);
    }
    std::system("CLS");
    std::cout << "Your level: " << level-1;
}

bool Engine::colision(bool action, COORD head, COORD board_dimensions)
{
    if (head.X == 0)
    {
        action = false;
    }
    else if (head.Y == 0)
    {
        action = false;
    }
    else if (head.X == board_dimensions.X)
    {
        action = false;
    }
    else if (head.Y == board_dimensions.Y)
    {
        action = false;
    }
    return action;
}

void Engine::print(char character, COORD location)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);
    std::cout << character;
}

char Engine::get_direction(char direction)
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            direction = 'w';
            break;
        case 's':
            direction = 's';
            break;
        case 'a':
            direction = 'a';
            break;
        case 'd':
            direction = 'd';
            break;
        }
    }
    return direction;
}

void Engine::set_speed()
{
    std::cout << "Choose snake speed: " << std::endl;
    std::cout << "1. Slow" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Fast" << std::endl;
    std::cin >> speed;
    switch (speed)
    {
    case 1:
        speed = 150;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 50;
        break;
    }
    std::system("CLS");
}