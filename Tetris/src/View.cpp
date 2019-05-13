#include "View.h"
#include <stdio.h>
#include <windows.h>
#include "Gamedef.h"
#include "Model.h"

View::View()
{
}

View::~View()
{
}

void View::init(void)
{
	for (int i = 0; i < GameAttribute::WIDTH; ++i)
	{
		setCursorPos(i, -1);
		printf("-");
		setCursorPos(i, GameAttribute::HEIGHT);
		printf("-");
	}

	for (int i = 0; i < GameAttribute::HEIGHT; ++i)
	{
		setCursorPos(-1, i);
		printf("|");
		for (int w = 0; w < GameAttribute::WIDTH; ++w)
			printf("  ");
		printf("|\n");
	}

	setCursorPos(GameAttribute::WIDTH+3, 0);
	printf("0    ");

	setCursorPos(0, GameAttribute::HEIGHT + 1);
	printf("                                        ");
	setCursorPos(0, GameAttribute::HEIGHT + 2);
	printf("                                        ");
}

void View::setCursorPos(int x,int y)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X = POS_START_X + (2 * x);
	Pos.Y = POS_START_Y + y;
	SetConsoleCursorPosition(hOut, Pos);
}

void View::setPosValue(int x, int y, char value)
{
	setCursorPos(x, y);
	printf("%c", value);
}

void View::displayBlock(std::vector<Point> _block)
{
	auto block = _block;

	for (int i = 0; i < 4; ++i)
	{
		setPosValue(block[i].x, block[i].y, DISPLAY_CHAR);
	}

	setCursorPos(0, GameAttribute::HEIGHT + 1);
}

void View::eliminateBlock(std::vector<Point> _block)
{
	auto block = _block;

	for (int i = 0; i < 4; ++i)
	{
		setPosValue(block[i].x, block[i].y, SPACE_CHAR);
	}

	setCursorPos(0, GameAttribute::HEIGHT + 1);
}

void View::refreshModel(const Model *_model)
{
	for (int y = 0; y < GameAttribute::HEIGHT; ++y )
	{
		for (int x = 0; x < GameAttribute::WIDTH; ++x)
		{
			setCursorPos(x, y);
			if (_model->m_board[y][x] == true)
				printf("*");
			else
				printf(" ");
		}
	}
}

void View::refreshScore(const int _score)
{
	setCursorPos(GameAttribute::WIDTH + 3, 0);
	printf("%d", _score);
}

void View::displayGameOver(const int _score)
{
	setCursorPos( 0 , GameAttribute::HEIGHT + 1);
	printf("Game Over!!!!! You Get %d Point\r\n", _score);
	setCursorPos(0, GameAttribute::HEIGHT + 2);
	printf("Renew Game Input SPACE ......");
}