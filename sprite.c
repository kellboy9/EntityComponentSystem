#include "sprite.h"

int create_sprite(struct sprites *_sprites, SDL_Renderer *renderer, const char* name)
{
	int sprite;
	for(sprite = 0; sprite < SPRITE_COUNT; ++sprite)
	{
		if(_sprites->textures[sprite] == NULL)
		{	
			char cat_name[12]; //8 for the file name, 4 for .bmp
			strcpy(cat_name, name);
			strcat(cat_name, ".bmp");	
			SDL_Surface *surface = SDL_LoadBMP(cat_name);
			_sprites->textures[sprite] = SDL_CreateTextureFromSurface(renderer, surface);
			_sprites->names[sprite] = name;
			return sprite;
		}
	}

	printf("Error: No more textures.\n");
	return SPRITE_COUNT;
}

int get_sprite(struct sprites *_sprites, SDL_Renderer *renderer, const char* name)
{
	//check if sprite exists in the struct
	int sprite;
	for(sprite = 0; sprite < SPRITE_COUNT; ++sprite)
	{
		if(_sprites->names[sprite] == name)
		{
			//if it does, then return that index
			return sprite;
		}
	}
	//else create it and return the new index
	return create_sprite(_sprites, renderer, name); 
}	


//TODO: possibly move these two functions into one function (late night brain != functional)
//TODO: move the sprite-setting from outside the entities and to the rendering component
