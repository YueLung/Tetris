#include "CtrlPlaying.h"
#include "..\Game.h"
#include "..\Model.h"
#include "..\Block\Block.h"

CtrlPlaying::CtrlPlaying(Game* _game) :Ctrl(_game)
{
	
}

CtrlPlaying::~CtrlPlaying()
{
}

bool CtrlPlaying::onEnter()
{
	return true;
}

bool CtrlPlaying::isAllowKeyEvent(int _data)
{
	auto model = getGame()->getModel();
	auto block = model->getBlock();

	if (_data == KeyCode::SPACE)
	{
		return true;
	}
	else
	{
		block->action(_data);

		if (model->isBlockOnEmptyPos() && model->isBlockInboard())
		{
			return true;
		}
		else
		{
			block->reverseAction();
			return false;
		}
	}
		
}

bool CtrlPlaying::isAllowRoundEnd(int _data)
{
	return getGame()->getModel()->isBlockRoundEnd();
}

bool CtrlPlaying::onKeyEvent(int _data)
{
	auto model = getGame()->getModel();
	auto block = model->getBlock();
	auto view = getGame()->getView();

	view->eliminateBlock(model->getBlock()->getBeforeBlock());

	if (_data == KeyCode::SPACE)
	{
		while (model->isBlockOnEmptyPos() && model->isBlockInboard())
		{
			block->finishAction();
			block->action(KeyCode::DOWN);
		}
		block->reverseAction();
		view->displayBlock(model->getBlock()->getBlock());
	}
	else
	{
		view->displayBlock(model->getBlock()->getBlock());
		model->getBlock()->finishAction();
	}
	
	return true;
}

bool CtrlPlaying::onRoundEnd(int _data)
{
	changeCtrl(CtrlEnum::RoundEnd);
	return true;
}

bool CtrlPlaying::onExit()
{
	return true;
}
