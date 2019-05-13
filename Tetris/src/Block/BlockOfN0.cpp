#include "BlockOfN0.h"

BlockOfN0::BlockOfN0()
{
	setBlockData();
}

BlockOfN0::~BlockOfN0()
{
}

void BlockOfN0::setBlockData()
{
	block.push_back(makePoint(0 ,0));
	block.push_back(makePoint(0, 1));
	block.push_back(makePoint(1, 1));
	block.push_back(makePoint(1, 2));

	MOVERIGHT(4);

	beforeBlock.assign(block.begin(),block.end());
}
