#include "system.h"

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
