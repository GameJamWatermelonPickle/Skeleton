#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>



j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// !!TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	for (int i = 0; i < tileList.count(); i++)
	{
		SDL_Texture* map = App->tex->Load(tilesetInfo.name.GetString());
		App->render->Blit(map, 0, 0);
	}
}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// !!TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map
	tilesetInfo.name.Clear();
	tileList.clear();
	LayerInfo.gid.clear();
	LayerInfo.name.Clear();

	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());
	pugi::xml_node mapInfo = map_file.child("map");
	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		
		// !!TODO 3: Create and call a private function to load and fill
		// all your map data
		LoadMap(mapInfo);
	}

	// !!TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
		
		LoadTileset();
		LoadLayer();

	if(ret == true)
	{
		// !!TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
		LOG("Successfully load map : %s", file_name);
		LOG("width = %i heigth = %i",MapInfo.width, MapInfo.height);
		LOG("title width = %i title heigth = %i",MapInfo.tilewidth, MapInfo.tileheight);
		LOG("----TILESET---");
		LOG("name: %s firstgid: %i", tilesetInfo.name.GetString(), tilesetInfo.firstgid);
		LOG("tile width: %i tile height: %i", tilesetInfo.tilewidth, tilesetInfo.tileheight);
		LOG("spacing: %i margin : %i",tilesetInfo.spacing, tilesetInfo.margin);

		
		
	}

	map_loaded = ret;

	return ret;
}

void j1Map::LoadMap(pugi::xml_node& nodeMap)
{
	
	if (!strcmp(nodeMap.attribute("orientation").as_string(), "orthogonal"))

		MapInfo.orientation = orthogonal;
	
	else if (!strcmp(nodeMap.attribute("orientation").as_string(), "isometric"))
	
		MapInfo.orientation = isometric;
	
	else if (!strcmp(nodeMap.attribute("orientation").as_string(), "staggered"))
	
		MapInfo.orientation = staggered;
	
	else
		MapInfo.orientation = hexagonal; 


	if (!strcmp(nodeMap.attribute("renderorder").as_string(), "right-down"))

		MapInfo.renderorder = right_down;

	else if (!strcmp(nodeMap.attribute("renderorder").as_string(), "right-up"))

		MapInfo.renderorder = right_up;

	else if (!strcmp(nodeMap.attribute("renderorder").as_string(), "left-down"))

		MapInfo.renderorder = left_down;
	else
		MapInfo.renderorder = left_up;

	MapInfo.width = nodeMap.attribute("width").as_int();
	MapInfo.height = nodeMap.attribute("height").as_int();
	MapInfo.tilewidth = nodeMap.attribute("tilewidth").as_int();
	MapInfo.tileheight = nodeMap.attribute("tileheight").as_int();
	MapInfo.nextobjectid = nodeMap.attribute("nextoobjectid").as_int();
}

void j1Map::LoadTileset()
{
	for (pugi::xml_node tileset = map_file.child("map").child("tileset"); tileset; tileset = tileset.next_sibling("tileset"))
	{
		
		p2SString tmp("%s%s%s", folder.GetString(),tileset.attribute("name").as_string(),".png");
		tilesetInfo.name = tmp;
		
		
		tilesetInfo.tilewidth = tileset.attribute("tilewidth").as_int();
		tilesetInfo.tileheight = tileset.attribute("tileheight").as_int();
		tilesetInfo.firstgid = tileset.attribute("firstgid").as_int();
		tilesetInfo.spacing = tileset.attribute("spacing").as_int();
		tilesetInfo.margin = tileset.attribute("margin").as_int();
		tileList.add(tilesetInfo);
		tilesetcount++;
	}	
}
//Load all layers
void j1Map::LoadLayer()
{
	for (pugi::xml_node layerset = map_file.child("map").child("layer"); layerset; layerset = layerset.next_sibling("layer"))
	{
		p2SString tmp("%s", layerset.attribute("name").as_string());
		LayerInfo.name = tmp;

		LayerInfo.height = layerset.attribute("height").as_int();
		LayerInfo.width = layerset.attribute("width").as_int();

		for (pugi::xml_node dataLayer = layerset.child("data").child("tile"); dataLayer; dataLayer = dataLayer.next_sibling("tile"))
		{
			LayerInfo.gid.add(dataLayer.attribute("gid").as_int());
			//HOMEWORK LOG ALL LAYERS
			LOG("%i", dataLayer.attribute("gid").as_int());
		}
		layerList.add(LayerInfo);
	}

}