#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "sprite.h"

/*
Graphics Class
Holds all information dealing with graphics for the game
*/

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
	/* SDL_Surface* loadImage
	Loads an image into the _spriteSheets map if it doesn't already exist
	As a result, each image will only ever be loaded once
	Returns the image form the map regardless of whether or not it was loaded
	*/
	SDL_Surface* loadImage(const std::string& filePath);
	/* void blitsSurface
	Draws a texture to a certain part of the screen	
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	/* void flip
	renders everything to the screen	
	*/
	void flip();
	/* void clear
	Clears the screen
	*/
	void clear();


	/* SDL_Renderer*
	Returns the renderer
	*/
	SDL_Renderer* getRenderer() const;


	/*
	Every time we draw a frame, we will first clear out the render
	After its been cleared out, we will blitsSurface, drawing on to the screen
	Flip will take whatever is on the render, and draw it to the screen
	*/

private:
	SDL_Window* _window; // where we are drawing to
	SDL_Renderer* _renderer; // what actually does all the drawing to the window


	// going to hold in memory, every sprite graphics loaded up into the game
	// if it is already loaded once, you won't have to load it again
	std::map<std::string, SDL_Surface*> _spriteSheets;

};

#endif