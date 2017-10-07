#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleSceneBaseballField.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	whiteGhostRight.PushBack({6,6,43,43});
	whiteGhostRight.PushBack({6,52,43,43});
	whiteGhostRight.PushBack({ 6,6,43,43 });
	whiteGhostRight.PushBack({6,100,42,42});

	whiteGhostLeft.PushBack({ 6,154,43,43 });
	whiteGhostLeft.PushBack({ 6,200,43,43 });
	whiteGhostLeft.PushBack({ 6,154,43,43 });
	whiteGhostLeft.PushBack({ 6,248,42,42 });

	whiteGhostUp.PushBack({112,6,37,41});
	whiteGhostUp.PushBack({112,52,32,40});
	whiteGhostUp.PushBack({ 112,6,37,41 });
	whiteGhostUp.PushBack({112,100,32,40});

	whiteGhostDown.PushBack({63,6,36,42});
	whiteGhostDown.PushBack({63,52,36,42});
	whiteGhostDown.PushBack({ 63,6,36,42 });
	whiteGhostDown.PushBack({63,100,36,42});

	redGhostRight.PushBack({ 6,7,43,43 });
	redGhostRight.PushBack({ 168,53,43,43 });
	redGhostRight.PushBack({ 168,7,43,43 });
	redGhostRight.PushBack({ 168,101,42,42 });

	redGhostLeft.PushBack({ 168,155,43,43 });
	redGhostLeft.PushBack({ 168,201,43,43 });
	redGhostLeft.PushBack({ 168,155,43,43 });
	redGhostLeft.PushBack({ 168,249,42,42 });

	redGhostUp.PushBack({274,8,35,42});
	redGhostUp.PushBack({274,54,33,41});
	redGhostUp.PushBack({ 274,8,35,42 });
	redGhostUp.PushBack({274,103,32,40});

	redGhostDown.PushBack({225,7,35,40});
	redGhostDown.PushBack({225,53,32,40});
	redGhostDown.PushBack({ 225,7,35,40 });
	redGhostDown.PushBack({225,101,32,42});

    blueGhostRight.PushBack({ 325,7,43,43 });
	blueGhostRight.PushBack({ 325,53,43,43 });
	blueGhostRight.PushBack({ 325,7,43,43 });
	blueGhostRight.PushBack({ 325,101,42,42 });

	blueGhostLeft.PushBack({ 324,156,43,43 });
	blueGhostLeft.PushBack({ 324,202,43,43 });
	blueGhostLeft.PushBack({ 324,156,43,43 });
	blueGhostLeft.PushBack({ 324,250,42,42 });

	blueGhostUp.PushBack({ 431,8,35,42 });
	blueGhostUp.PushBack({ 431,54,33,41 });
	blueGhostUp.PushBack({ 431,8,35,42 });
	blueGhostUp.PushBack({ 431,103,32,40 });

	blueGhostDown.PushBack({ 382,7,35,40 });
	blueGhostDown.PushBack({ 382,53,32,40 });
	blueGhostDown.PushBack({ 382,7,35,40 });
	blueGhostDown.PushBack({ 382,101,32,42 });

}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* c1, Collider* c2)
{
	//App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->baseball_field->color += 10;
	App->baseball_field->death++;
}