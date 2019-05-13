#pragma once 
#include <vector> 

#define MOVERIGHT(num) for(int i=0;i<num;++i){\
							moveRight();}\

typedef struct {
	int x;
	int y;
}Point;

class Block
{
public:
	Block();
	~Block();

	virtual void setBlockData() = 0;
	Point makePoint(const int x, const int y);
	void action(const int);
	void reverseAction(void);
	void finishAction(void);

	inline std::vector<Point> getBlock(void) { return block; };
	inline std::vector<Point> getBeforeBlock(void) { return beforeBlock; };

	int getBlockTopmost(void);

	void moveUp(void);
protected:
	void moveRight(void);
	void moveLeft(void);
	void moveDown(void);
	void rotate(void);

	int getBlockHeight(void);
	int getBlockLeftmost(void);
	int getBlockBottommost(void);
	
protected:
	std::vector<Point> block;
	std::vector<Point> beforeBlock; 
};

