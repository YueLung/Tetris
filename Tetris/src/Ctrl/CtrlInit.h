#pragma once
#include "Ctrl.h"
class Game;

class CtrlInit:public Ctrl
{
public:
	CtrlInit(Game *_game);
	~CtrlInit();

	bool onEnter();
	bool onExit();

};

