#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// !!TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct tilesetInfo
{
	p2SString name= nullptr;
	unsigned int firstgid = 0, tilewidth = 0, tileheight = 0, spacing = 0, margin = 0;
};

// !!TODO 1: Create a struct needed to hold the information to Map node

enum Orientation { orthogonal, isometric, staggered, hexagonal };
enum Renderorder { right_down, right_up, left_down, left_up };
struct mapInfo
{
	Orientation orientation = orthogonal;
	Renderorder renderorder = right_down;
	unsigned int width=0, height=0, tilewidth=0, tileheight=0, nextobjectid=0;

};
//HOMEWORK 1- STRUCT LAYER

struct layerInfo
{
	p2SString name = nullptr;
	int width = 0, height = 0;
	p2List<int> gid;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);
	
private:
	void LoadMap(pugi::xml_node&);
	void LoadTileset();
	void LoadLayer();
	p2List<tilesetInfo> tileList;
	p2List<layerInfo> layerList;

public:

	// !!TODO 1: Add your struct for map info as public for now	
	mapInfo MapInfo;
	tilesetInfo tilesetInfo;
	int tilesetcount = 0;
	layerInfo LayerInfo;
	
private:
	SDL_Texture* map = nullptr;
	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__