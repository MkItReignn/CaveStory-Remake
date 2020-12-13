#ifndef LEVEL_H
#define LEVEL_H

#include "../header/door.h"
#include "../header/tile.h"
#include "../header/globals.h"
#include "../header/rectangle.h"
#include <string>
#include <vector>
#include "../header/slope.h"
#include "../header/animatedtile.h"

class Player;
class Graphics;
class Enemy;
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

class Level {
public:
	Level();
	Level(std::string mapName, Graphics& graphics);
	~Level();
	void update(int elapsedTime, Player &player);
	void draw(Graphics& graphics);

	std::vector<Rectangle> checkTileCollisions(const Rectangle& other);
	std::vector<Slope> checkSlopeCollisions(const Rectangle& other);

	std::vector<Door> checkDoorCollisions(const Rectangle& other);
	std::vector<Enemy*> checkEnemyCollisions(const Rectangle& other);

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
	std::vector<Slope> _slopes;

	std::vector<AnimatedTile> _animatedTileList;
	std::vector<AnimatedTileInfo> _animatedTileInfos;

	std::vector<Door> _doorList;

	std::vector<Enemy*> _enemies;
	/* void loadMap
	Loads a map, will only be called within the level class it self
	*/
	void loadMap(std::string mapName, Graphics& graphics);

	Vector2 getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight);
	
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