#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "component.h"

#define SPRITE_COUNT 50

#ifndef SPRITE_H
#define SPRITE_H

//sprite defined as a structure containing a name and a texture (held in video memory with SDL)
//struct containing the textures, and their names (somewhat analogous to std::map)
//needs to be separate from cmp_render because there are as many cmp_renders as there are objects, but the textures need to be able to be reused. 

struct sprites
{
	SDL_Texture *textures[SPRITE_COUNT]; //Throws incomplete element type error??? //EDIT: must be pointer because SDL_Texture is an opaque type
	const  char *names[SPRITE_COUNT];
};


int get_sprite(struct sprites *_sprites, SDL_Renderer *renderer, const char* name);
int create_sprite(struct sprites *_sprites, SDL_Renderer *renderer, const char* name);

#endif
