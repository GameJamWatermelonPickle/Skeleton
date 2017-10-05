#include "ModuleCollision.h"
#include "p2List.h"
#include "p2Defs.h"
#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Input.h"
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
	//nose si hacerlo con un while es correcto, si se os ocurre una manera mas rapida, hacedlo
	p2List_item<Collider*>* col;
	col = colliders.start;
	while ( col!= NULL)
	{
		if (col->data->to_delete == true) {
			col->next->prev = col->prev;
			col->prev->next = col->next;
			RELEASE(col->data);
			col = col->next;
		}
	}

	return true;

}

bool ModuleCollision::Update(float dt)
{
	//debug function
	
	//Mirar colision con otros objetos todos con todos : usar la lista
	p2List_item<Collider*>* c1;
	p2List_item<Collider*>* c2;
	if (colliders.start != NULL) {
		for (c1 = colliders.start; c1->next != NULL; c1 = c1->next) {
			for (c2 = colliders.start; c2->next != NULL; c2 = c2->next) {
				c1->data->CheckCollision(c2->data->rect);
			}

		}
	}
	return true;
	
	}

bool ModuleCollision::CleanUp()
{
	//iterador de borrar todo con la funcion RELEASE(*puntero)
	p2List_item<Collider*>* c_item;
	c_item = colliders.start;
	while (c_item != NULL)
	{
		RELEASE(c_item->data);
		c_item = c_item->next;
	}

	return true;

}
void ModuleCollision::deleteCollider(Collider*c)
{
	c->to_delete = true;
}
Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, j1Module* callback)
{
	Collider new_collider(rect, type, callback);
	colliders.add(&new_collider);
	
	return &new_collider;
}

bool ModuleCollision::DrawDebug()
{
	p2List_item<Collider*>* print_col;
	for (print_col = colliders.start;print_col->next!=NULL;print_col=print_col->next)
	{
		App->render->DrawQuad(print_col->data->rect, 255, 255, 0, 150); //faltaria un if para poner diferentes colores o añadir el color como atributo al colider
	}
	return true;
}

bool Collider::CheckCollision(const SDL_Rect& r) const
{


	return true;
}