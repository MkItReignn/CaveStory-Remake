#include "animated_sprite.h"
#include "graphics.h"
#include "sprite.h"

/* AnimatedSprite class
Animates our sprites
*/

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
	int width, int height, float posX, float posY, float timeToUpdate) :
		Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
		_frameIndex(0),
		_timeToUpdate(timeToUpdate),
		_timeElapsed(0),
		_visible(true),
		_currentAnimationOnce(false),
		_currentAnimation("")
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset) {
	// temporarily holds rectangles that is going to be put in the map
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);

	}
	this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
	this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));

}

void AnimatedSprite::resetAnimations() {
	this->_animations.clear();
	this->_offsets.clear();

}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
	this->_currentAnimation = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible) {
	this->_visible = visible;
}

void AnimatedSprite::stopAnimation() {
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();
	
	// add on to timer
	this->_timeElapsed += elapsedTime;
	// check if it is time to update

	if (this->_timeElapsed > this->_timeToUpdate) {
		// if we are moving to the next frame, must subtract form time elapsed
		this->_timeElapsed -= this->_timeElapsed;
		// if its not at the last currentAnimation, increment frameIndex
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1) {
			this->_frameIndex++;
		}
		else {
			// we hit the last frame, and must stop
			if (this->_currentAnimationOnce == true) {
				this->setVisible(false);
			}
			this->_frameIndex = 0;
			this->animationDone(this->_currentAnimation);
		}
	}
}


void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
	if (this->_visible) {
		// Create object SDL_Rect to show where in the screen we are drawing
		SDL_Rect destinationRectangle;
		// set up
		// pushes it to offsets
		destinationRectangle.x = x + this->_offsets[this->_currentAnimation].x;
		destinationRectangle.y = y + this->_offsets[this->_currentAnimation].y;
		destinationRectangle.w = this->_sourceRect.w * globals::SPRITE_SCALE;
		destinationRectangle.h = this->_sourceRect.h * globals::SPRITE_SCALE;

		// grab the correct vector, and the animation from the vector itself
		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
		graphics.blitSurface(this->_spriteSheet, &sourceRect, &destinationRectangle);

	}
}

void AnimatedSprite::animationDone(std::string currentAnimation) {

}

void AnimatedSprite::setupAnimations() {
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}