#ifndef __ENEMY_RIGHT_SPIRAL_H__
#define __ENEMY_RIGHT_SPIRAL_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Right_Spiral : public Enemy
{
private:
	Animation fly;
	iPoint originalpos;
	Path movement;

public:

	Enemy_Right_Spiral(int x, int y);

	void OnCollision(Collider* c1, Collider* c2);

	void Move();
};

#endif 
