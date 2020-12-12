#ifndef SPRITE_H
#define SPRITE_H



#include <SDL.h>
#include <string>

#include "rectangle.h"
#include "globals.h"

class Graphics;
/* Sprite Class
Holds all information for individual sprites
*/


class Sprite {
public:
	Sprite();
	// posX posY -> where the sprite will be positioned on the screen
	Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);

	const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle& other) const;

	const inline float getX() const { return this->_x; }
	const inline float getY() const { return this->_y; }

	void setSourceRectX(int value);
	void setSourceRectY(int value);

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	float _x, _y;
	// tight box around the character
	Rectangle _boundingBox;

private:
	

};

#endif // !SPRITE_H
