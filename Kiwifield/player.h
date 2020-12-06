#pragma once
#include "const.h"
#include "stage.h"
#include "dynamicPoint.h"
#include <vector>

using namespace olc;
using namespace std;

class Player : public DynamicPoint
{
public:
	vi2d size = { 8, 8 };
	vf2d scale = { 1, 1 };

	bool canJump = false;
	bool jump = false;
	bool drawSprite = false;
	bool gravity = true;

	vi2d collisionPixel;
	PixelGameEngine* g;
	
	Sprite* sprite;
	Decal* decal;
    
public:
	Player(vf2d p, PixelGameEngine& g);
	void Animate(float time);
	~Player();

	void KeyboardInput(float time, Stage& stage);
	void Logic(float time, Stage& stage);

	void MoveUp(Stage& stage) override;
};
