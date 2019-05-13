#pragma once
#include "Ctrl.h"
class Game;

class CtrlRoundEnd :public Ctrl
{
public:
	CtrlRoundEnd(Game* _game);
	~CtrlRoundEnd();

	bool onEnter();
	bool onExit();

	//bool isAllowKeyEvent(int);
	//bool onKeyEvent(int);
};

