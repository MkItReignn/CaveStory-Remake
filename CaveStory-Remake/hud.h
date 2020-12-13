#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "player.h"

class Graphics;

class HUD {
public:
	HUD();
	HUD(Graphics& graphics, Player& player);
	void update(int elapsedTime, Player &player);
	void draw(Graphics& graphics);

private:
	Player _player;

	// Health Sprites
	Sprite _healthBarSprite;
	Sprite _healthNumber1;
	Sprite _currentHealthBar;
	// Exp Sprites
	Sprite _lvlWord; // Lv
	Sprite _lvNumber; // Similar to health number
	Sprite _expBar;
	// Weapon Info
	Sprite _slash;
	Sprite _dashes;
};

#endif