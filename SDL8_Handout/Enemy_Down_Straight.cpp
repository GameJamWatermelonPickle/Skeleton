#include "Application.h"
#include "Enemy_Down_Straight.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"
#include "ModuleSceneBaseballField.h"

#include <math.h>



Enemy_Down_Straight::Enemy_Down_Straight(int x, int y) : Enemy(x, y)
{
	whiteGhostRight.PushBack({ 6,6,43,43 });
	whiteGhostRight.PushBack({ 6,52,43,43 });
	whiteGhostRight.PushBack({ 6,6,43,43 });
	whiteGhostRight.PushBack({ 6,100,42,42 });

	whiteGhostLeft.PushBack({ 6,154,43,43 });
	whiteGhostLeft.PushBack({ 6,200,43,43 });
	whiteGhostLeft.PushBack({ 6,154,43,43 });
	whiteGhostLeft.PushBack({ 6,248,42,42 });

	whiteGhostUp.PushBack({ 112,6,37,41 });
	whiteGhostUp.PushBack({ 112,52,32,40 });
	whiteGhostUp.PushBack({ 112,6,37,41 });
	whiteGhostUp.PushBack({ 112,100,32,40 });

	whiteGhostDown.PushBack({ 63,6,36,42 });
	whiteGhostDown.PushBack({ 63,52,36,42 });
	whiteGhostDown.PushBack({ 63,6,36,42 });
	whiteGhostDown.PushBack({ 63,100,36,42 });

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

void Enemy_Down_Straight::Move()
{
	position = originalpos + movement.GetCurrentPosition();
	animation = &whiteGhostUp;
}


void Enemy_Down_Straight::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
	{
		App->baseball_field->color += 10;
		App->baseball_field->death++;
	}
}