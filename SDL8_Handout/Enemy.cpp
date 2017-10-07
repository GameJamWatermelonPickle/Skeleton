#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleSceneBaseballField.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	whiteGhostRight.PushBack({6,6,42,42});
	whiteGhostRight.PushBack({9,52,42,42});
	whiteGhostRight.PushBack({7,100,42,42});

	whiteGhostUp.PushBack({112,7,37,41});
	whiteGhostUp.PushBack({115,53,32,40});
	whiteGhostUp.PushBack({116,100,32,40});

	whiteGhostDown.PushBack({63,6,35,41});
	whiteGhostDown.PushBack({65,52,33,41});
	whiteGhostDown.PushBack({66,100,32,41});

	redGhostRight.PushBack({198,7,42,41});
	redGhostRight.PushBack({171,53,39,42});
	redGhostRight.PushBack({169,101,42,41});

	redGhostUp.PushBack({225,7,35,42});
	redGhostUp.PushBack({227,53,33,41});
	redGhostUp.PushBack({228,102,32,40});

	redGhostDown.PushBack({274,9,35,40});
	redGhostDown.PushBack({277,54,32,40});
	redGhostDown.PushBack({278,101,32,42});


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
	App->baseball_field->death++;
}