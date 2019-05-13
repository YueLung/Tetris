#include "CtrlRoundStart.h"
#include "..\Game.h"
#include "..\Model.h"

CtrlRoundStart::CtrlRoundStart(Game* _game) : Ctrl(_game)
{
}


CtrlRoundStart::~CtrlRoundStart()
{
}

bool CtrlRoundStart::onEnter()
{
	auto model = getGame()->getModel();
	auto view = getGame()->getView();
	bool isGameOver = false;

	model->createBlock();

	while(!model->isBlockOnEmptyPos())
	{
		isGameOver = true;
		model->getBlock()->moveUp();
	}

	if (isGameOver)
	{
		view->displayBlock(model->getBlock()->getBlock());
		changeCtrl(CtrlEnum::End);
	}

	return true;
}

bool CtrlRoundStart::isAllowKeyEvent(int _data)
{
	return getGame()->getModel()->isBlockOnEmptyPos();
}

bool CtrlRoundStart::onKeyEvent(int _data)
{
	auto model = getGame()->getModel();
	auto view = getGame()->getView();

	view->displayBlock(model->getBlock()->getBlock());

	changeCtrl(CtrlEnum::Playing);
	return false;
}


bool CtrlRoundStart::onExit()
{
	return true;
}