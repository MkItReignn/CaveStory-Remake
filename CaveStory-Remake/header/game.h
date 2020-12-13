#ifndef GAME_H
#define GAME_H

#include "../header/graphics.h"
#include "../header/player.h"
#include "../header/level.h"
#include "../header/hud.h"


class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	Player _player;

	Level _level;

	HUD _hud;

	Graphics _graphics;
};


#endif