#include "entity.h"

unsigned int create_entity(struct entities *_entities)
{
	unsigned int entity;
	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if(_entities->component_mask[entity] == CMP_NONE)
		{
			return entity;
		}

	}
	
	printf("Error: no more entities.\n");
	return ENTITY_COUNT;
}

void destroy_entity(struct entities *_entities, unsigned int entity)
{
	_entities->component_mask[entity] = CMP_NONE;
}

unsigned int create_player(struct entities *_entities, float x, float y)
{
	unsigned int entity = create_entity(_entities);
	_entities->component_mask[entity] = CMP_POSITION | CMP_COLLISION | CMP_RENDER;
	_entities->positions[entity].x = x;
	_entities->positions[entity].y = y;
	_entities->collisions[entity].x = x;
	_entities->collisions[entity].y = y;
	_entities->renders[entity].name = "player";
	return entity;
}
