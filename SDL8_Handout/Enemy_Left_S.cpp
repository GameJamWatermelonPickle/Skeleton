#include "Application.h"
#include "Enemy_Left_S.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"
#include "ModuleSceneBaseballField.h"

Enemy_Left_S::Enemy_Left_S(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,6,24,24 });
	fly.PushBack({ 38, 6, 24, 24 });
	fly.PushBack({ 71, 6, 24, 24 });
	fly.PushBack({ 104, 6, 24, 24 });
	fly.PushBack({ 137, 6, 24, 24 });
	fly.PushBack({ 170, 6, 24, 24 });
	fly.PushBack({ 203, 6, 24, 24 });
	fly.PushBack({ 236, 6, 24, 24 });
	fly.speed = 0.2f;

	animation = &fly;


	movement.PushBack({ 1.0f,-2.0f }, 57, &fly);
	movement.PushBack({ 1.0f,2.0f }, 114, &fly);
	movement.PushBack({ 1.0f,-2.0f }, 57, &fly);


	originalpos.x = x;
	originalpos.y = y;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);




}

void Enemy_Left_S::Move()
{
	position = originalpos + movement.GetCurrentPosition();
}


void Enemy_Left_S::OnCollision(Collider* c1, Collider* c2) {
	if (c1->type == COLLIDER_ENEMY && (c2->type == COLLIDER_TOWER || c2->type == COLLIDER_PLAYER))
	{
		App->baseball_field->color += 10;
		App->baseball_field->death++;
	}
}