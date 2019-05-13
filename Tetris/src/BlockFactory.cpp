#include "BlockFactory.h"
#include "Block\Block.h"
#include "Block\BlockOfL0.h"
#include "Block\BlockOfL1.h"
#include "Block\BlockOfN0.h"
#include "Block\BlockOfN1.h"
#include "Block\BlockOfO.h"
#include "Block\BlockOfT.h"
#include "Block\BlockOfI.h"

#include <time.h>

BlockFactory::BlockFactory()
{
}

BlockFactory::~BlockFactory()
{
}

Block* BlockFactory::createBlock()
{
	srand(time(NULL));
	BlockEnum blockRand = (BlockEnum)(rand() % BLOCK_SUM);

	Block* block = NULL;

	switch (blockRand)
	{
		case BlockEnum::O:
			block = new BlockOfO();
			break;
		case BlockEnum::I:
			block = new BlockOfI();
			break;
		case BlockEnum::T:
			block = new BlockOfT();
			break;
		case BlockEnum::N0:
			block = new BlockOfN0();
			break;
		case BlockEnum::N1:
			block = new BlockOfN1();
			break;
		case BlockEnum::L0:
			block = new BlockOfL0();
			break;
		case BlockEnum::L1:
			block = new BlockOfL1();
			break;
		default:
			//"Error"
			break;
	}

	return block;
}
