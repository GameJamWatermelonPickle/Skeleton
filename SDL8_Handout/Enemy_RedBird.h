#ifndef __ENEMY_REDBIRD_H__
#define __ENEMY_REDBIRD_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_RedBird : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

	Path path1;

public:

	Enemy_RedBird(int x, int y);

	void Move();
};

#endif // __ENEMY_REDBIRD_H__