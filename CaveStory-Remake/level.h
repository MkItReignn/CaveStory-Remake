#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"
#include "globals.h"
#include "rectangle.h"
#include <string>
#include <vector>

class Graphics;
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

class Level {
public:
	Level();
	Level(std::string mapName, Vector2 spawnPoint, Graphics& graphics);
	~Level();
	void update(int elapsedTime);
	void draw(Graphics& graphics);

	std::vector<Rectangle> checkTileCollisions(const Rectangle& other);

	const Vector2 getPlayerSpawnPoint() const;

private:
	std::string _mapName;
	Vector2 _spawnPoint;
	// The size of the width and the height of the entire map
	Vector2 _size;
	Vector2 _tileSize;

	SDL_Texture* _backgroundTexture;

	std::vector<Tile> _tileList;
	std::vector<Tileset> _tilesets;
	std::vector<Rectangle> _collisionRects;

	/* void loadMap
	Loads a map, will only be called within the level class it self
	*/
	void loadMap(std::string mapName, Graphics& graphics);

};



// Tileset structure
struct Tileset {
	SDL_Texture* Texture;
	int FirstGid;

	Tileset() {
		this->FirstGid = -1;
	}

	Tileset(SDL_Texture* texture, int firstGid) {
		this->Texture = texture;
		this->FirstGid = firstGid;
	}
};

#endif