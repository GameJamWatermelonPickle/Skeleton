#include "ModuleCollision.h"
#include "p2List.h"
#include "p2Defs.h"
#include "j1App.h"
#include "j1Module.h"
#include "p2Log.h"


ModuleCollision::ModuleCollision(): j1Module()
{

}
ModuleCollision::~ModuleCollision()
{

}

bool ModuleCollision::Awake(pugi::xml_node& config)
{
	bool ret = true;

	matrix[COLLIDER_WALL][COLLIDER_PLAYER]= true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = false;

	return ret;
}

bool ModuleCollision::PreUpdate()
{

	//eliminar todos los colliders que tengan el to_delete a true





}

bool ModuleCollision::Update(float dt)
{
	//debug function

	//Mirar colision con otros objetos todos con todos : usar la lista



}

bool ModuleCollision::CleanUp()
{
	//iterador de borrar todo con la funcion RELEASE(*puntero)
	

}
void ModuleCollision::deleteCollider(Collider*c)
{

}
Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, j1Module* callback)
{

}

bool ModuleCollision::DrawDebug()
{




}

bool Collider::CheckCollision(const SDL_Rect& r) const
{



}