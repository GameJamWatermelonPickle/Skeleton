#include "Application.h"
#include "Enemy_Down_Spiral.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"
#include "ModuleSceneBaseballField.h"

Enemy_Down_Spiral::Enemy_Down_Spiral(int x, int y) : Enemy(x, y)
{
	blueGhostRight.PushBack({ 325,7,49,42 });
	blueGhostRight.PushBack({ 328,53,43,43 });
	blueGhostRight.PushBack({ 326,101,42,42 });

	blueGhostLeft.PushBack({ 325,156,49,43 });
	blueGhostLeft.PushBack({ 325,202,43,43 });
	blueGhostLeft.PushBack({ 324,250,43,42 });

	blueGhostUp.PushBack({ 431,8,37,42 });
	blueGhostUp.PushBack({ 434,54,34,41 });
	blueGhostUp.PushBack({ 435,101,33,40 });

	blueGhostDown.PushBack({ 382,7,39,40 });
	blueGhostDown.PushBack({ 384,53,32,40 });
	blueGhostDown.PushBack({ 385,101,33,42 });

	blueGhostDown.speed = 0.15f;
	blueGhostUp.speed = 0.15f;
	blueGhostRight.speed = 0.15f;
	blueGhostLeft.speed = 0.15f;

	movement.PushBack({ 2.0f,-1.0f }, 180, animation);
	movement.PushBack({ -1.0f,-2.0f }, 251, animation);
	movement.PushBack({ -2.0f,1.0f }, 180, animation);
	movement.PushBack({ 1.0f,2.0f }, 150, animation);
	movement.PushBack({ 1.0f,-2.0f }, 251, animation);


	originalpos.x = x;
	originalpos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Down_Spiral::Move()
{
	position = originalpos + movement.GetCurrentPosition();
	bool left;
	float angle;


	if (ballposx >= position.x) {
		left = false;
	}
	else {
		left = true;
	}

	angle = ((float)acos((((ballposx - position.x) * 0) + ((ballposy - position.y) * 1)) / (sqrt((double)((ballposx - position.x)*(ballposx - position.x) + (ballposy - position.y)*(ballposy - position.y)))*sqrt((double)(0 * 0 + 1 * 1))))) * ANGLE_CONVERT;
	if (left == false) {
		if (angle <= 45) {
			animation = &blueGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &blueGhostRight;
		}
		else {
			animation = &blueGhostUp;
		}
	}
	else {
		if (angle <= 45) {
			animation = &blueGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &blueGhostLeft;
		}
		else {
			animation = &blueGhostUp;
		}
	}
}


void Enemy_Down_Spiral::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_PLAYER_SHOT))
	{
		if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
		App->baseball_field->color += 10;
		App->baseball_field->death++;
	}
}