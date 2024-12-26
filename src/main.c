#include <stdio.h>
#include <stfbool.h>
#include <SDL2/SDL.h>

SDL_Window* window;

bool initialize_window(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}

   window = SDL_CreateWindow();

	return true;
}

int main(void) {
   
   /* TODO: Create a SDL window */
   initialize_window();

   return 0;
}