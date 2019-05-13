#include "Block.h"
#include "..\Gamedef.h"

Block::Block()
{
}

Block::~Block()
{
}

Point Block::makePoint(int x, int y)
{
	Point res;
	res.x = x;
	res.y = y;

	return res;
}

void Block::action(const int dir)
{
	switch (dir)
	{
		case KeyCode::UP :
			rotate();
			break;
		case KeyCode::DOWN:
			moveDown();
			break;
		case KeyCode::LEFT:
			moveLeft();
			break;
		case KeyCode::RIGHT:
			moveRight();
			break;
	}
}

void Block::reverseAction(void)
{
	block.assign(beforeBlock.begin(), beforeBlock.end());
}

void Block::finishAction(void)
{
	beforeBlock.assign(block.begin(), block.end());
}

void Block::moveRight(void)
{
	for (int i = 0; i < block.size(); ++i)
	{
		block[i].x += 1;
	}
}

void Block::moveLeft(void)
{
	for (int i = 0; i < block.size(); ++i)
	{
		block[i].x -= 1;
	}
}

void Block::moveUp(void)
{
	for (int i = 0; i < block.size(); ++i)
	{
		block[i].y -= 1;
	}
}

void Block::moveDown(void)
{
	for (int i = 0; i < block.size(); ++i)
	{
		block[i].y += 1;
	}
}

void Block::rotate(void)
{
	int height  = getBlockHeight();
	int TopMost = getBlockTopmost();
	int LeftMost = getBlockLeftmost();

	for (int i = 0; i < block.size(); ++i)
	{
		int tmp_x = block[i].x;

		block[i].x = LeftMost + height - (block[i].y - TopMost);
		block[i].y = tmp_x - LeftMost + TopMost;
	}
}

int Block::getBlockHeight(void)
{
	int min = INT_MAX;

	for (int i = 0; i < block.size(); ++i)
	{
		min = block[i].y < min ? block[i].y : min;
	}
	
	return getBlockBottommost() - min;
}



int Block::getBlockLeftmost(void)
{
	int min = INT_MAX;

	for (int i = 0; i < block.size(); ++i)
		min = block[i].x < min ? block[i].x : min;

	return min;
}

int Block::getBlockBottommost(void)
{
	int max = INT_MIN;

	for (int i = 0; i < block.size(); ++i)
		max = block[i].y > max ? block[i].y : max;

	return max;
}

int Block::getBlockTopmost(void)
{
	int min = INT_MAX;

	for (int i = 0; i < block.size(); ++i)
		min = block[i].y < min ? block[i].y : min;

	return min;
}