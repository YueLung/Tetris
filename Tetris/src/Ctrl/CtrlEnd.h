#pragma once
#include "Ctrl.h"
class Game;

class CtrlEnd :public Ctrl
{
public:
	CtrlEnd(Game* _game);;
	~CtrlEnd();

	bool onEnter();
	bool onExit();

	bool isAllowKeyEvent(int);
	bool onKeyEvent(int);
};

