#ifndef ENEMY_H
#define ENEMY_H

#include "animated_sprite.h"
#include "globals.h"
#include "player.h"

#include <string>

class Graphics;


class Enemy : public AnimatedSprite {
public:
	Enemy();
	Enemy(Graphics& graphics, std::string filePath, int sourceX,
		int sourceY, int width, int height, Vector2 spawnPoint, int timeToUpdate);

	virtual void update(int elapsedTime, Player &player);
	virtual void draw(Graphics& graphics);
	
	const inline int getMaxHealth() const { return this->_maxHealth; }
	const inline int getCurrentHealth() const { return this->_currHealth; }

protected:
	Direction _direction;
	
	int _maxHealth;
	int _currHealth;

};


class Bat : public Enemy {
public:
	Bat();
	Bat(Graphics& graphics, Vector2 spawnPoint);
	void update(int elapsedTime, Player &player);
	void draw(Graphics& graphics);

	void animationDone(std::string currentAnimation);
	void setupAnimations();
private:

};


#endif // !ENEMY_H
