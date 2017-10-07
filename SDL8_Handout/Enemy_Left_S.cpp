#include "Application.h"
#include "Enemy_Left_S.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"
#include "ModuleSceneBaseballField.h"

Enemy_Left_S::Enemy_Left_S(int x, int y) : Enemy(x, y)
{
	redGhostRight.PushBack({ 6,7,43,43 });
	redGhostRight.PushBack({ 168,53,43,43 });
	redGhostRight.PushBack({ 168,7,43,43 });
	redGhostRight.PushBack({ 168,101,42,42 });

	redGhostLeft.PushBack({ 168,155,43,43 });
	redGhostLeft.PushBack({ 168,201,43,43 });
	redGhostLeft.PushBack({ 168,155,43,43 });
	redGhostLeft.PushBack({ 168,249,42,42 });

	redGhostUp.PushBack({ 274,8,35,42 });
	redGhostUp.PushBack({ 274,54,33,41 });
	redGhostUp.PushBack({ 274,8,35,42 });
	redGhostUp.PushBack({ 274,103,32,40 });

	redGhostDown.PushBack({ 225,7,35,40 });
	redGhostDown.PushBack({ 225,53,32,40 });
	redGhostDown.PushBack({ 225,7,35,40 });
	redGhostDown.PushBack({ 225,101,32,42 });

	redGhostDown.speed = 0.15f;
	redGhostLeft.speed = 0.15f;
	redGhostUp.speed = 0.15f;
	redGhostRight.speed = 0.15f;



	movement.PushBack({ 1.0f,-2.0f }, 57, animation);
	movement.PushBack({ 1.0f,2.0f }, 114, animation);
	movement.PushBack({ 1.0f,-2.0f }, 57, animation);


	originalpos.x = x;
	originalpos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Left_S::Move()
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
			animation = &redGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &redGhostRight;
		}
		else {
			animation = &redGhostUp;
		}
	}
	else {
		if (angle <= 45) {
			animation = &redGhostDown;
		}

		else if (angle > 45 && angle < 135) {
			animation = &redGhostLeft;
		}
		else {
			animation = &redGhostUp;
		}
	}
}


void Enemy_Left_S::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_PLAYER_SHOT))
	{
		if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
		App->baseball_field->color += 10;
		App->baseball_field->death++;
	}
}