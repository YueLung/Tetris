#pragma once
#include "Ctrl.h"
class Game;

class CtrlPlaying :public Ctrl
{
public:
	CtrlPlaying(Game* _game);
	~CtrlPlaying();

	bool onEnter();
	bool onExit();

	bool isAllowKeyEvent(int);
	bool isAllowRoundEnd(int);

	bool onKeyEvent(int);
	bool onRoundEnd(int);
};

