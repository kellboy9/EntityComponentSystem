#include "system.h"

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
			printf("%s at %f, %f\n", render->sprite, pos->x, pos->y);
		}

	}
}
