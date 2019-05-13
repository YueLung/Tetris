#include "BlockOfI.h"

BlockOfI::BlockOfI()
{
	setBlockData();
}

BlockOfI::~BlockOfI()
{
}

void BlockOfI::setBlockData()
{
	block.push_back(makePoint(0, 0));
	block.push_back(makePoint(1, 0));
	block.push_back(makePoint(2, 0));
	block.push_back(makePoint(3, 0));

	MOVERIGHT(2);

	beforeBlock.assign(block.begin(),block.end());
}
