#include "BlockOfN1.h"

BlockOfN1::BlockOfN1()
{
	setBlockData();
}

BlockOfN1::~BlockOfN1()
{
}

void BlockOfN1::setBlockData()
{
	block.push_back(makePoint(1 ,0));
	block.push_back(makePoint(1, 1));
	block.push_back(makePoint(0, 1));
	block.push_back(makePoint(0, 2));

	MOVERIGHT(4);

	beforeBlock.assign(block.begin(),block.end());
}
