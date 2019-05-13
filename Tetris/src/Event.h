#pragma once
#include "Gamedef.h"
class Ctrl;
typedef bool (Ctrl::* isAllowFun)(int);
typedef bool (Ctrl::* onFun)(int);

class Event
{
public:
	Event(isAllowFun, onFun);
	~Event();
	inline onFun onEvent() { return m_onEvent; }
	inline isAllowFun isAllowEvent() { return m_isAllowEvent; }
private:
	onFun m_onEvent;
	isAllowFun m_isAllowEvent;
};

