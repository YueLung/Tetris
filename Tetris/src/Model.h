#pragma once
#include "Gamedef.h"
#include "View.h"
class Block;

class Model
{
	friend View;
public:
	Model();
	~Model();

	void init(void);
	void createBlock();
	bool isBlockOnEmptyPos();
	bool isBlockInboard();
	bool isBlockRoundEnd();

	void setBlock2Board();

	void doRoundEnd();

	Block* getBlock();
	inline int getScore() { return m_score; }
	
private:
	bool isWinLine(int);
	void initBoardLine(int);
	void moveDownBoardLine(int);
	void addScore(const int);

private:
	int m_score;
	bool m_board[GameAttribute::HEIGHT][GameAttribute::WIDTH];
	Block* m_block;
};

