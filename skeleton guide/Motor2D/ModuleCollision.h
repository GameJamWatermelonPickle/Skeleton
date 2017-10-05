#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 100
#include "SDL/include/SDL.h"
#include "j1Module.h"
#include "p2List.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL,
	COLLIDER_PLAYER,
	COLLIDER_ENEMY,
	
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false, to_active = true;
	COLLIDER_TYPE type;
	j1Module* callback = nullptr;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, j1Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public j1Module
{
public:
	ModuleCollision();
	~ModuleCollision();
	bool Awake(pugi::xml_node&);
	bool PreUpdate();
	bool Update(float);
	bool CleanUp();

	void deleteCollider(Collider*);
	Collider* AddCollider(SDL_Rect , COLLIDER_TYPE , j1Module*);
	bool DrawDebug();
	//Colision Player con Map Collider::CheckPlayerMapCollision()

private:
	bool matrix[MAX_COLLIDERS][MAX_COLLIDERS];
	bool debug = false;
	p2List<Collider*> colliders;
	
};

#endif // __ModuleCollision_H__
