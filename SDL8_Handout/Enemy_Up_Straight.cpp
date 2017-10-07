#include "Application.h"
#include "Enemy_Up_Straight.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"
#include "ModuleSceneBaseballField.h"

Enemy_Up_Straight::Enemy_Up_Straight(int x, int y) : Enemy(x, y)
{

	whiteGhostRight.PushBack({ 6,6,49,42 });
	whiteGhostRight.PushBack({9,52,43,43 });
	whiteGhostRight.PushBack({ 7,100,42,42 });

	whiteGhostLeft.PushBack({ 7,154,49,43 });
	whiteGhostLeft.PushBack({ 7,200,43,43 });
	whiteGhostLeft.PushBack({ 6,248,43,42 });

	whiteGhostUp.PushBack({ 112,7,37,42 });
	whiteGhostUp.PushBack({ 115,53,34,41 });
	whiteGhostUp.PushBack({ 116,100,33,40 });

	whiteGhostDown.PushBack({ 63,6,39,40 });
	whiteGhostDown.PushBack({ 65,52,32,40 });
	whiteGhostDown.PushBack({ 66,100,33,42 });

	whiteGhostDown.speed = 0.15f;
	whiteGhostUp.speed = 0.15f;
	whiteGhostLeft.speed = 0.15f;
	whiteGhostRight.speed = 0.15f;

	//animation = &fly;


	movement.PushBack({ 0.0f,-2.0f }, 1, animation);



	originalpos.x = x;
	originalpos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Up_Straight::Move()
{
	position = originalpos + movement.GetCurrentPosition();
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
			animation = &whiteGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &whiteGhostRight;
		}
		else {
			animation = &whiteGhostUp;
		}
	}
	else {
		if (angle <= 45) {
			animation = &whiteGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &whiteGhostLeft;
		}
		else {
			animation = &whiteGhostUp;
		}
	}
}


void Enemy_Up_Straight::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
	{
		App->baseball_field->color += 10;
		App->baseball_field->death++;
	}
}