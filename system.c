#include "system.h"


//RENDERING SUBSYSTEM
void sys_render_update(struct entities *_entities, struct sprites *_sprites, SDL_Renderer *renderer)
{
	//UI/HUD elements defined as render components without position
	//Object sprites defined as render components + position

	unsigned int entity;
	struct cmp_position *pos;
	struct cmp_position *render;

	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if((_entities->component_mask[entity] & CMP_RENDER) == CMP_RENDER)
		{
			//TODO: use get_sprite here with the sprite database and draw it with SDL_RenderCopy()
			int sprite = get_sprite(_sprites, renderer, _entities->renders[entity].name);

			//fill out position rect if it contains a position component, otherwise use defaults.
			int w, h;
			SDL_Rect pos_rect;
			pos_rect.x = 0;
			pos_rect.y = 0;
			if((_entities->component_mask[entity] & CMP_POSITION) == CMP_POSITION)
			{
				pos_rect.x = _entities->positions[entity].x;
				pos_rect.y = _entities->positions[entity].y;
			}
			SDL_QueryTexture(_sprites->textures[sprite], NULL, NULL, &w, &h);
			pos_rect.w = w;
			pos_rect.h = h;
			SDL_RenderCopy(renderer, _sprites->textures[sprite], NULL, &pos_rect);
		}
	}

}

void sys_render_print_info(struct entities *_entities)
{
	unsigned int entity;
	struct cmp_position *pos;
	struct cmp_render *render;

	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if((_entities->component_mask[entity] & (CMP_POSITION | CMP_RENDER)) == (CMP_POSITION | CMP_RENDER))
		{
			pos = &(_entities->positions[entity]);
			render = &(_entities->renders[entity]);
			printf("%s at %f, %f\n", render->name, pos->x, pos->y);
		}

	}
}

//INPUT SUBSYSTEM
void sys_input_update(struct entities *_entities, int key[KEY_COUNT])
{
	int entity;
	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if((_entities->component_mask[entity] & CMP_INPUT_PLAYER) == CMP_INPUT_PLAYER)
		{
			if(key[SDLK_UP])
				_entities->positions[entity].y--;
			if(key[SDLK_DOWN])
				_entities->positions[entity].y++;
			if(key[SDLK_LEFT])
				_entities->positions[entity].x--;
			if(key[SDLK_RIGHT])
				_entities->positions[entity].x++;
		}
	}
}
