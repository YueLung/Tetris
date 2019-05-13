#pragma once

const int POS_START_X = 25;
const int POS_START_Y = 1;

const char DISPLAY_CHAR = '*';
const char SPACE_CHAR   = ' ';
const int  LINE_SCORE = 1000;

namespace KeyCode {
	const int UP    = 72;
	const int DOWN  = 80;
	const int LEFT  = 75;
	const int RIGHT = 77;
	const int SPACE	= 32;
}

enum CtrlEnum{
	Init,
	RoundStart,
	Playing,
	RoundEnd,
	End
};

enum EventEnum {
	KeyEvent,
	CheckRoundEnd
};


namespace GameAttribute {
	const int HEIGHT = 20;
	const int WIDTH = 10;
}


