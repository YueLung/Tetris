#include "Ctrl.h"
#include "..\Game.h"


Ctrl::Ctrl(Game* _game):m_game(_game)
{
	addEvent(EventEnum::KeyEvent,      &Ctrl::isAllowKeyEvent, &Ctrl::onKeyEvent);
	addEvent(EventEnum::CheckRoundEnd, &Ctrl::isAllowRoundEnd, &Ctrl::onRoundEnd);
}

Ctrl::~Ctrl()
{
}

void Ctrl::addEvent(EventEnum _name, isAllowFun _isAllowFun, onFun _onFun)
{
	m_eventMap[_name] = std::make_pair(_isAllowFun, _onFun);
}

bool Ctrl::onEvent(EventEnum _type , int _data)
{
	auto it = m_eventMap.find(_type);

	if (it != m_eventMap.end())
	{
		if ( (this->*(it->second.first))(_data) )
		{
			(this->*(it->second.second))(_data);
			return true;
		}
	}
		
	return false;
}
void Ctrl::changeCtrl(CtrlEnum _ctrl)
{
	m_game->changeCtrl(_ctrl);
}

bool Ctrl::onEnter()
{
	return true;
}

bool Ctrl::isAllowKeyEvent(int _data)
{
	return false;
}

bool Ctrl::onKeyEvent(int _data)
{
	return false;
}

bool Ctrl::isAllowRoundEnd(int _data)
{
	return false;
}

bool Ctrl::onRoundEnd(int _data)
{
	return false;
}

bool Ctrl::onExit()
{
	return true;
}

