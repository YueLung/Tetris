#pragma once
class Block;

enum BlockEnum { O = 0, I, T, N0, N1, L0, L1, Sum };
const int BLOCK_SUM = 7;

class BlockFactory
{
public:
	BlockFactory();
	~BlockFactory();
	static Block* createBlock();
};

