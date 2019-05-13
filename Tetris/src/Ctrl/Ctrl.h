#pragma once
#include "..\Gamedef.h"
#include <map>
class Game;

class Ctrl
{
	typedef bool (Ctrl::* isAllowFun)(int);
	typedef bool (Ctrl::* onFun)(int);

public:
	Ctrl(Game*);
	~Ctrl();

	virtual bool onEnter();
	virtual bool onExit();

	void changeCtrl(CtrlEnum);
	void addEvent(EventEnum , isAllowFun, onFun);
	bool onEvent(EventEnum,int);
	
	virtual bool isAllowKeyEvent(int);
	virtual bool isAllowRoundEnd(int);

	virtual bool onKeyEvent(int);
	virtual bool onRoundEnd(int);

	inline Game* getGame() {return m_game;}

private:
	Game* m_game;
	std::map<EventEnum, std::pair<isAllowFun, onFun> > m_eventMap;
};

