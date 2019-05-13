#include "CtrlRoundEnd.h"
#include "..\Game.h"
#include "..\Model.h"

CtrlRoundEnd::CtrlRoundEnd(Game* _game) :Ctrl(_game)
{

}

CtrlRoundEnd::~CtrlRoundEnd()
{
}

bool CtrlRoundEnd::onEnter()
{
	auto model = getGame()->getModel();
	auto view = getGame()->getView();

	model->setBlock2Board();
	model->doRoundEnd();

	view->refreshModel(model);
	view->refreshScore(model->getScore());

	changeCtrl(CtrlEnum::RoundStart);
	return true;
}

bool CtrlRoundEnd::onExit()
{
	return true;
}