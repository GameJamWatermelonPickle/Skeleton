#ifndef __ENEMY_LEFT_STRAIGHT_H__
#define __ENEMY_LEFT_STRAIGHT_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Left_Straight : public Enemy
{
private:
	Animation whiteGhostUp;
	Animation whiteGhostDown;
	Animation whiteGhostLeft;
	Animation whiteGhostRight;
	iPoint originalpos;
	Path movement;

public:

	Enemy_Left_Straight(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif 