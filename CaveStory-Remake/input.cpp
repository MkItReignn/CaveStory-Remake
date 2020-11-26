#include "input.h"

/*
Input Class
Keeps tracks of keyboard states
*/


// This funciton gets called at the beginning of each new frame
// to reset the keys that are no longer relevant
void Input::beginNewFrame() {
	// reset because they only matter for the frame that we are in
	// you don't want the same keys to be set in the next frame, to start fresh
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}
// this gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event) {
	// since we pressed the key, we want to set that key and pressed key into true
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

// this gets called when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	// we no longer holding it, hence false
	this->_heldKeys[event.key.keysym.scancode] = false;
}

// Checks if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}
// Checks if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}
// Checks if a certain key is being held
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}