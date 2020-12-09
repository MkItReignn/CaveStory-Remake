#ifndef PLAYER_H
#define PLAYER_H


#include "animated_sprite.h"
#include "globals.h"
#include "slope.h"

class Graphics;


class Player : public AnimatedSprite {

public:
	Player();
	Player(Graphics& graphics, Vector2 spawnPoint);
	void draw(Graphics& graphics);
	void update(float elapsedTime);
	/* void moveLeft
	Moves the player left by -dx
	*/
	void moveLeft();
	/* void moveRight
	Moves the player right by dx
	*/
	void moveRight();
	/* void stopMoving
	Stops moving the player 
	*/
	void stopMoving();
	/* void jump
	Starts jumping	
	*/
	void jump();


	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle>& others);
	void handleSlopeCollisoins(std::vector<Slope>& others);

	const float getX() const;
	const float getY() const;

private:
	// change in x and change in y positoin
	float _dx, _dy;

	Direction _facing;

	// true if we are on the ground, false if we are not
	bool _grounded;
};

#endif // !PLAYER_H
