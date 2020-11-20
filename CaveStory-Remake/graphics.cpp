#include <SDL.h>
#include "graphics.h"

/*
Graphics Class
Holds all information dealing with graphics for the game
*/

// constructor needs to create the window and initialise
Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory");
}

// destructor needs to destroy the window to clean everything
Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}