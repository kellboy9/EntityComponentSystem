#include <stdio.h>
#include "component.h"

#ifndef ENTITY_H
#define ENTITY_H

#define ENTITY_COUNT 100

struct entities
{
	int component_mask[ENTITY_COUNT];
	struct cmp_position positions[ENTITY_COUNT];
	struct cmp_render renders[ENTITY_COUNT];
	struct cmp_collision collisions[ENTITY_COUNT];	
};

unsigned int create_entity(struct entities *_entities);

void destroy_entity(struct entities *_entities, unsigned int entity);

unsigned int create_player(struct entities *_entities, float x, float y);



#endif
