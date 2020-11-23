#include <SDL.h>
#include <algorithm>

#include "game.h"
#include "graphics.h"
#include "input.h"


/*
Game Class
This class holds all information for our main game loop
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;

}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING); // SDL_Init initialises things // SDL_INIT_EVERYTHING initialises everything
	this->gameLoop();

}

Game::~Game() {

}

// one of the most important functions in the entire program
// 
void Game::gameLoop() {
	Graphics graphics;
	Input input; 
	SDL_Event event; // this SDL_Event object will hold what ever event that happens during that frame
	// it stores the event through SDL by checking
	
	// gets the number of miliseconds passed since initialisation of SDL
	int LAST_UPDATE_TIME = SDL_GetTicks();

	// start game loop
	while (true) {
		// in each new frame, press/release key will be reset
		input.beginNewFrame();

		// every time around the loop, it will poll for pending events
		// SDL is going to find what events will happen and will stick it into event
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {

				// key.repeat, makes sure you are not holding down a key
				// if we want a single key press, we don't want the key to be held, so must check
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			} 
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			// when you close the program or quit the program
			else if (event.type == SDL_QUIT) {
				return;
			} 		 

		}

		// if key pressed was esc, quit the game loop
		if (input.wasKeyPresed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		// how long it took for the while loop to occur
		// found by current - last update
		const int CURRENT_TIME_MS = SDL_GetTicks();
		// whole purpose of getting ticks is to find Elapsed time		
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		// if this frame took less than the maximum time, we will just use that, thats fine
		// if it too more than its maximum time, it is bound by maximum time
		// must limit frame or weird things may happen
		// we want the physics to depend on how long the frame took 
		// if one person runs this program in a slow and fast computer, you want to get to the same place
		// in the same time, even though the physics may look choppy
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics& graphics) {

}

void Game::update(float elapsedTime) {

}