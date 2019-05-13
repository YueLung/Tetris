#include "CtrlEnd.h"
#include "..\Game.h"
#include "..\Model.h"

CtrlEnd::CtrlEnd(Game* _game) :Ctrl(_game)
{

}

CtrlEnd::~CtrlEnd()
{
}

bool CtrlEnd::onEnter()
{
	auto view = getGame()->getView();
	auto model = getGame()->getModel();

	view->displayGameOver(model->getScore());

	return true;
}

bool CtrlEnd::isAllowKeyEvent(int _data)
{
	if (_data == KeyCode::SPACE)
		return true;
	else
		return false;
}

bool CtrlEnd::onKeyEvent(int _data)
{
	changeCtrl(CtrlEnum::Init);
	return true;
}

bool CtrlEnd::onExit()
{
	return true;
}