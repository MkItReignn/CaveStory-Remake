#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
private:
	SDL_Window* _window; // where we are drawing to
	SDL_Renderer* _renderer; // what actually does all the drawing to the window
};

#endif