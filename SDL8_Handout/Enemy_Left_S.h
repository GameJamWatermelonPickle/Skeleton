#ifndef __ENEMY_LEFT_S_H__
#define __ENEMY_LEFT_S_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Left_S : public Enemy
{
private:

	Animation redGhostUp;
	Animation redGhostDown;
	Animation redGhostLeft;
	Animation redGhostRight;
	iPoint originalpos;
	Path movement;

public:

	Enemy_Left_S(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif
