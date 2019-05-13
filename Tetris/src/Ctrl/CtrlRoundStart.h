#pragma once
#include "Ctrl.h"
class Game;

class CtrlRoundStart:public Ctrl
{
public:
	CtrlRoundStart(Game* _game);
	~CtrlRoundStart();

	bool onEnter();
	bool onExit();

	bool isAllowKeyEvent(int);
	bool onKeyEvent(int);
};

