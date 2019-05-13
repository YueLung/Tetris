#include "Game.h"

#include <conio.h>
#include <windows.h>

#include "Ctrl\CtrlInit.h"
#include "Ctrl\CtrlPlaying.h"
#include "Ctrl\CtrlRoundStart.h"
#include "Ctrl\CtrlRoundEnd.h"
#include "Ctrl\CtrlEnd.h"

Game::Game()
{
	m_view  = new View();
	m_model = new Model();
	m_curCtrl = NULL;
	initCtrl();
}

Game::~Game()
{
	delete m_view;
	delete m_model;

	for (auto i = m_ctrlMap.begin(); i != m_ctrlMap.end(); ++i)
	{
		delete i->second;
	}
}

bool Game::start(void)
{
	int count = 0;
	int keyCode;

	changeCtrl(CtrlEnum::Init);
	
	while (1)
	{
		Sleep(20);
		count++;

		//Ä²µoDown
		if (count > 25)
		{
			count = 0;
			onEvent(EventEnum::CheckRoundEnd, 1000);
			onEvent(EventEnum::KeyEvent, KeyCode::DOWN);
		}

		if (_kbhit())
		{
			onEvent(EventEnum::CheckRoundEnd, 1000);

			keyCode = _getch();

			if (hasKeyCode(keyCode))
			{
				if (onEvent(EventEnum::KeyEvent, keyCode) && keyCode == KeyCode::DOWN)
				{
					count = 0;
				}	
			}	
		}
	}
}

bool Game::onEvent(EventEnum _type, int _data)
{
	return m_curCtrl->onEvent(_type, _data);
}
void Game::initCtrl()
{
	addCtrl(CtrlEnum::Init	    , new CtrlInit(this)       );
	addCtrl(CtrlEnum::RoundStart, new CtrlRoundStart(this) );
	addCtrl(CtrlEnum::Playing   , new CtrlPlaying(this)    );
	addCtrl(CtrlEnum::RoundEnd  , new CtrlRoundEnd(this)   );
	addCtrl(CtrlEnum::End		, new CtrlEnd(this)		   );
}

bool Game::hasKeyCode(const int _key)
{
	if (_key == KeyCode::UP || _key == KeyCode::DOWN || _key == KeyCode::LEFT
		|| _key == KeyCode::RIGHT || _key == KeyCode::SPACE)
	{
		return true;
	}

	return false;
}

void Game::addCtrl(CtrlEnum _name, Ctrl *_ctrl)
{
	m_ctrlMap[_name] = _ctrl;
}

void Game::changeCtrl(CtrlEnum _name)
{
	if (m_ctrlMap.find(_name) != m_ctrlMap.end())
	{
		m_curCtrl = m_ctrlMap[_name];
		if (m_curCtrl)
		{
			m_curCtrl->onEnter();
		}
	}
	else
	{
		printf("changeCtrl: §ä¤£¨ì%d", _name);
	}
}
