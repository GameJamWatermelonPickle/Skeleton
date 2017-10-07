#ifndef __ENEMY_LEFT_SPIRAL_H__
#define __ENEMY_LEFT_SPIRAL_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Left_Spiral : public Enemy
{
private:
	Animation blueGhostUp;
	Animation blueGhostRight;
	Animation blueGhostDown;
	Animation blueGhostLeft;
	iPoint originalpos;
	Path movement;

public:

	Enemy_Left_Spiral(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif 
