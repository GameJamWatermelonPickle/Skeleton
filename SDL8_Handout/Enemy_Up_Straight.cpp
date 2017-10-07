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


	movement.PushBack({ 0.0f,2.0f }, 1, animation);



	originalpos.x = x;
	originalpos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Up_Straight::Move()
{
	position = originalpos + movement.GetCurrentPosition();
	animation = &whiteGhostDown;
}


void Enemy_Up_Straight::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER || c2->type == COLLIDER_PLAYER_SHOT))
	{
		if(c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
		App->baseball_field->color += 20;

		App->baseball_field->death++;
	}
}