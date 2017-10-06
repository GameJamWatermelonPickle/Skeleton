#include "Application.h"
#include "Enemy_RedBird.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "Path.h"

Enemy_RedBird::Enemy_RedBird(int x, int y) : Enemy(x, y)
{
	fly.PushBack({5,6,24,24});
	fly.PushBack({38, 6, 24, 24});
	fly.PushBack({71, 6, 24, 24});
	fly.PushBack({104, 6, 24, 24});
	fly.PushBack({137, 6, 24, 24});
	fly.PushBack({170, 6, 24, 24});
	fly.PushBack({203, 6, 24, 24});
	fly.PushBack({236, 6, 24, 24});
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({0, 0, 24, 24}, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;

	path1.PushBack({ +0.5f, +0.0f }, 140);
	path1.PushBack({ -0.5f, +0.5f }, 40);
	path1.PushBack({ +0.0f, +0.5f }, 10);
	path1.PushBack({ +0.5f, +0.0f }, 60);
	path1.PushBack({ +0.0f, +0.5f }, 110);
	path1.PushBack({ +0.5f, +0.0f }, 70);
	path1.PushBack({ +0.0f, +0.5f }, 30);
	path1.PushBack({ -0.5f, +0.0f }, 90);
	
}

void Enemy_RedBird::Move()
{
/*	if(going_up)
	{
		if(wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if(wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}
	*/
	
	if ((position.x > App->player->position.x)&& collA == false)
		position.x -= 2;
	if ((position.x < App->player->position.x) && collD == false)
		position.x += 2;
	if ((position.y > App->player->position.y) && collW == false)
		position.y -= 1;
	if ((position.y < App->player->position.y) && collS == false)
		position.y += 1;

	collW = false;
	collA = false;
	collS = false;
	collD = false;
}


void Enemy_RedBird::OnCollision(Collider* c1, Collider* c2){

	if (c2->type == COLLIDER_ENEMY) {
		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y == 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collW = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x == 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collA = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x != 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y == 1)

			collS = true;

		if ((c1->rect.x + c1->rect.w) - c2->rect.x == 1 && (c2->rect.x + c2->rect.w) - c1->rect.x != 1 && (c2->rect.y + c2->rect.h) - c1->rect.y != 1 && (c1->rect.y + c1->rect.h) - c2->rect.y != 1)

			collD = true;

	}
}