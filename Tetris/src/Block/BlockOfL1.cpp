#include "BlockOfL1.h"

BlockOfL1::BlockOfL1()
{
	setBlockData();
}

BlockOfL1::~BlockOfL1()
{
}

void BlockOfL1::setBlockData()
{
	block.push_back(makePoint(1 ,0));
	block.push_back(makePoint(1, 1));
	block.push_back(makePoint(1, 2));
	block.push_back(makePoint(0, 2));

	MOVERIGHT(4);

	beforeBlock.assign(block.begin(),block.end());
}
