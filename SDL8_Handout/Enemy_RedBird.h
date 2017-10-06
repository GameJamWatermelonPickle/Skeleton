#ifndef __ENEMY_REDBIRD_H__
#define __ENEMY_REDBIRD_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RedBird : public Enemy
{
private:
	Animation fly;
	iPoint originalpos;
	Path movement;

public:

	Enemy_RedBird(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif // __ENEMY_REDBIRD_H__