#pragma once
#include <map>
#include <string>
#include "Gamedef.h"
#include "View.h"
#include "Model.h"
#include "Ctrl\Ctrl.h"

class Game
{
public:
	Game();
	~Game();

	bool start(void);
	void initCtrl();
	void addCtrl(CtrlEnum _name , Ctrl *_ctrl);
	void changeCtrl(CtrlEnum);
	bool onEvent(EventEnum,int);
	bool hasKeyCode(const int);

	inline Model* getModel() { return m_model; };
	inline View*  getView()  { return m_view;  };
private:
	Model *m_model;
	View *m_view;
	Ctrl *m_curCtrl;
	std::map<CtrlEnum, Ctrl*> m_ctrlMap;
};

