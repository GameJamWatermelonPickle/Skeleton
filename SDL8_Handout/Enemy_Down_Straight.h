#ifndef __ENEMY_DOWN_STRAIGHT_H__
#define __ENEMY_DOWN_STRAIGHT_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Down_Straight : public Enemy
{
private:
	Animation whiteGhostUp;
	Animation whiteGhostDown;
	Animation whiteGhostLeft;
	Animation whiteGhostRight;
	iPoint originalpos;
	Path movement;

public:

	Enemy_Down_Straight(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif 