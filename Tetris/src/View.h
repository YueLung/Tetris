#pragma once
#include <vector> 
#include "Block\Block.h"

class Model;

class View
{
public:
	View();
	~View();

	void init(void);
	void setCursorPos(int x,int y);
	void setPosValue(int x, int y, char value);

	void displayBlock(std::vector<Point>);
	void eliminateBlock(std::vector<Point>);

	void refreshModel(const Model*);

	void refreshScore(const int);

	void displayGameOver(const int);

};
