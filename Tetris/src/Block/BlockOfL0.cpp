#include "BlockOfL0.h"

BlockOfL0::BlockOfL0()
{
	setBlockData();
}

BlockOfL0::~BlockOfL0()
{
}

void BlockOfL0::setBlockData()
{
	block.push_back(makePoint(0 ,0));
	block.push_back(makePoint(0, 1));
	block.push_back(makePoint(0, 2));
	block.push_back(makePoint(1, 2));

	MOVERIGHT(4);

	beforeBlock.assign(block.begin(),block.end());
}
