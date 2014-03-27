#include <stdio.h>
#include <SDL2/SDL.h>
#include "entity.h"
#include "component.h"
#include "system.h"

//create the databases
struct entities entities;
struct sprites sprites;
int key[KEY_COUNT];

int initialize_entities()
{
	//ENTITY_COUNT 500
	printf("%d\n", ENTITY_COUNT);
	int player = create_player(&entities, 5.0f, 10.0f);		
	create_player(&entities, 100.0f, 16.0f);
	create_player(&entities, 200.0f, 64.0f);
	create_entity(&entities);
}

int main(int argc, char** argv)
{

	//Set up SDL
	SDL_Window *window;
	SDL_Renderer *renderer;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Error: Could not intitialize SDL. %s", SDL_GetError());

	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer);
	if(window==NULL)
		printf("Error: Could not create window. %s", SDL_GetError());
	if(renderer==NULL)
		printf("Error: Could not create renderer. %s", SDL_GetError());

	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	SDL_RenderSetLogicalSize(renderer, 640, 400);

	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

	initialize_entities();

	int done = 0;
	while(!done)
	{
		SDL_Event ev;
		while(SDL_PollEvent(&ev))
		{
			//pass ev to sys_input
			switch(ev.type)
			{
				case SDL_QUIT:
					done = 1;
					break;
				case SDL_KEYDOWN:
					if(ev.key.keysym.sym == SDLK_ESCAPE)
						done = 1;
					if(ev.key.keysym.sym == SDLK_p)
						sys_render_print_info(&entities);

					key[ev.key.keysym.sym] = 1;
					break;
				case SDL_KEYUP:
					key[ev.key.keysym.sym] = 0;
					break;
			}
		}
		//INPUT SUBSYSTEM UPDATE
		sys_input_update(&entities, key);

		SDL_RenderClear(renderer);
		sys_render_update(&entities, &sprites, renderer);
		//sys_render_print_info(&entities);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
