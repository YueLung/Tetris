#include "Model.h"
#include "Block\BlockOfL0.h"
#include "BlockFactory.h"

Model::Model():m_block(NULL)
{
	init();
	m_score = 0;
}

Model::~Model()
{
	delete m_block;
}

void Model::createBlock()
{
	if (m_block)
	{
		//printf("delete block");
		delete m_block;
		m_block = NULL;
	}

	m_block = BlockFactory::createBlock();
}

void Model::init(void)
{
	for (int i = 0; i < GameAttribute::HEIGHT; ++i)
	{
		for (int j = 0; j < GameAttribute::WIDTH; ++j)
		{
			m_board[i][j] = false;
		}
	}
}

bool Model::isBlockOnEmptyPos()
{
	auto block = m_block->getBlock();

	for (int i = 0; i < block.size(); ++i)
	{
		if (block[i].y < 0)
			continue;

		if ( m_board[block[i].y][block[i].x] == true)
		{
			return false;
		}
	}
	return true;
}

bool Model::isBlockInboard()
{
	auto block = m_block->getBlock();

	for (int i = 0; i < block.size(); ++i)
	{
		if (block[i].y > 19 || block[i].y < 0 || block[i].x > 9 || block[i].x < 0 )
		{
			return false;
		}
	}
	return true;
}

bool Model::isBlockRoundEnd()
{
	auto block = m_block->getBlock();

	for (int i = 0; i < block.size(); ++i)
	{
		if (block[i].y + 1 > 19 || m_board[block[i].y + 1][block[i].x] == true)
		{
			return true;
		}
	}
	return false;
}

void Model::setBlock2Board()
{
	auto block = m_block->getBlock();

	for (int i = 0; i < block.size(); ++i)
	{
		m_board[block[i].y][block[i].x] = true;
	}
}

void Model::doRoundEnd()
{
	auto block = m_block->getBlock();
	int  BlockTopmost = m_block->getBlockTopmost();

	for (int i = 0; i < block.size(); ++i)
	{
		if (isWinLine(BlockTopmost + i))
		{
			addScore(LINE_SCORE);
			initBoardLine(BlockTopmost + i);
			moveDownBoardLine(BlockTopmost + i);
		}
	}
}

bool Model::isWinLine(int line)
{
	for (int i = 0; i < GameAttribute::WIDTH; ++i)
	{
		if (m_board[line][i] == false)
			return false;
	}
	return true;
}

void Model::initBoardLine(int line)
{
	for (int i = 0; i < GameAttribute::WIDTH; ++i)
	{
		m_board[line][i] = false;
	}

}

void Model::moveDownBoardLine(int line)
{
	for (int i = line; i > 0; --i)
	{
		for (int x = 0; x < GameAttribute::WIDTH; ++x)
		{
			m_board[i][x] = m_board[i-1][x];
		}
	}
}

void Model::addScore(const int _add)
{
	m_score += _add;
}

Block* Model::getBlock()
{
	return m_block;
}
