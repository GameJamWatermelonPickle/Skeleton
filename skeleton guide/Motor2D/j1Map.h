#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "ModuleCollision.h"

struct Properties
{
	p2SString name = nullptr;
	p2List<uint> value;
	~Properties() { value.clear(); }
};
struct MapLayer
{
	p2SString name = nullptr;
	int width = 0, height = 0;
	p2List<uint> gid;
	Properties properti;

	inline uint Get(int x, int y) const
	{

		if ((x < 0 || y < 0) || (y*width + x) >= gid.count())
		{
			return 0;
		}
		else
		{
			return gid[(y*width) + x];
		}

	}

	~MapLayer() { gid.clear(); }
};


// ----------------------------------------------------
struct TileSet
{
	// TODO 7: Create a method that receives a tile id and returns it's Rectfind the Rect associated with a specific tile id
	SDL_Rect GetTileRect(int id) const;

	p2SString			name;
	int					firstgid;
	int					margin;
	int					spacing;
	int					tile_width;
	int					tile_height;
	SDL_Texture*		texture;
	int					tex_width;
	int					tex_height;
	int					num_tiles_width;
	int					num_tiles_height;
	int					offset_x;
	int					offset_y;
};

enum MapTypes
{
	MAPTYPE_UNKNOWN = 0,
	MAPTYPE_ORTHOGONAL,
	MAPTYPE_ISOMETRIC,
	MAPTYPE_STAGGERED
};
// ----------------------------------------------------
struct MapData
{
	int					width;
	int					height;
	int					tile_width;
	int					tile_height;
	SDL_Color			background_color;
	MapTypes			type;
	p2List<TileSet*>	tilesets;
	// TODO 2: Add a list/array of layers to the map!
	p2List<MapLayer*>	layermap;
	p2List<Collider*> dataCollider;
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

	// TODO 8: Create a method that translates x,y coordinates from map positions to world positions
	iPoint MapToWorld(int x, int y) const;

private:

	bool LoadMap();
	bool LoadTilesetDetails(pugi::xml_node& tileset_node, TileSet* set);
	bool LoadTilesetImage(pugi::xml_node& tileset_node, TileSet* set);

	bool LoadLayer(pugi::xml_node& node, MapLayer* layer);
	bool LoadProperties(pugi::xml_node& node, MapLayer* layer);

public:

	MapData data;
	Collider *mapCollision= nullptr;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__