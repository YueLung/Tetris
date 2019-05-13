#include "CtrlInit.h"
#include "..\Game.h"
#include "..\Model.h"

CtrlInit::CtrlInit(Game* _game):Ctrl(_game)
{

}

CtrlInit::~CtrlInit()
{
}

bool CtrlInit::onEnter()
{
	auto view  = getGame()->getView();
	auto model = getGame()->getModel();

	model->init();
	view->init();
	view->refreshModel(model);

	changeCtrl(CtrlEnum::RoundStart);
	return true;
}

bool CtrlInit::onExit()
{
	return true;
}