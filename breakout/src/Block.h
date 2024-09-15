#pragma once
#include "Utils.h"
#include "Ball.h"

struct Block
{
	Vector2 offSet; //refers to a corner
	Vector2 pos;
	int height;
	int width;
	int lives;
};

namespace BlockSpace
{
	void CreateBlocks();
	void UpdateBlocks(Ball& ball);
	void DrawBlocks();
	void DrawBlock(Block block);
}
