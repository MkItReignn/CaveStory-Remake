#ifndef  INPUT_H
#define INPUT_H

#include <SDL.h>

#include <map>

class Input {
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);

	bool wasKeyPresed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
private:
	// map will store what keys are being held
	// reason for bool: able to pass any key from the key board, and this map will know whether it was held, pressed or released
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;

};

#endif // ! INPUT_H
