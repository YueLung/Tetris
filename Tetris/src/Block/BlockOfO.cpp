#include "BlockOfO.h"

BlockOfO::BlockOfO()
{
	setBlockData();
}

BlockOfO::~BlockOfO()
{
}

void BlockOfO::setBlockData()
{
	block.push_back(makePoint(0 ,0));
	block.push_back(makePoint(1, 0));
	block.push_back(makePoint(0, 1));
	block.push_back(makePoint(1, 1));

	MOVERIGHT(4);

	beforeBlock.assign(block.begin(),block.end());
}
