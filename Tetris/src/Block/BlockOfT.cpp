#include "BlockOfT.h"

BlockOfT::BlockOfT()
{
	setBlockData();
}

BlockOfT::~BlockOfT()
{
}

void BlockOfT::setBlockData()
{
	block.push_back(makePoint(1 ,0));
	block.push_back(makePoint(0, 1));
	block.push_back(makePoint(1, 1));
	block.push_back(makePoint(2, 1));

	MOVERIGHT(3);

	beforeBlock.assign(block.begin(),block.end());
}
