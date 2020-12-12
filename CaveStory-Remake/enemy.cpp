#include "enemy.h"

// Base enemy class
Enemy::Enemy() {}

Enemy::Enemy(Graphics& graphics, std::string filePath, int sourceX, int sourceY, int width,
	int height, Vector2 spawnPoint, int timeToUpdate) :
	AnimatedSprite(graphics, filePath, sourceX, sourceY, width, height,
		spawnPoint.x, spawnPoint.y, timeToUpdate),
	_direction(LEFT),
	_maxHealth(0),
	_currHealth(0)
{}

void Enemy::update(int elapsedTime, Player &player) {
	AnimatedSprite::update(elapsedTime);

}

void Enemy::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

// Bat class
Bat::Bat() {}

Bat::Bat(Graphics& graphics, Vector2 spawnPoint) :
	Enemy(graphics, "content/sprites/NpcCemet.png", 32, 32, 16, 16, spawnPoint, 140)
{
	this->setupAnimations();
	this->playAnimation("FlyLeft");

}

void Bat::update(int elapsedTime, Player& player) {
	this->_direction = player.getX() > this->_x ? RIGHT : LEFT;
	this->playAnimation(this->_direction == RIGHT ? "FlyRight" : "FlyLeft");

	Enemy::update(elapsedTime, player);
}

void Bat::draw(Graphics& graphics) {
	Enemy::draw(graphics);
}

void Bat::animationDone(std::string currentAnimation) {

}

void Bat::setupAnimations() {
	this->addAnimation(3, 2, 32, "FlyLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 2, 48, "FlyRight", 16, 16, Vector2(0, 0));
}
