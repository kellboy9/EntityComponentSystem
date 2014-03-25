#include <stdio.h>

#ifndef COMPONENT_H
#define COMPONENT_H

struct cmp_position
{
	float x;
	float y;
};
struct cmp_render
{
	const char* sprite;
	//SDL_Surface* sprite;
};
struct cmp_collision
{
	float x;
	float y;
	float w;
	float h;
};

enum component
{
	CMP_NONE = 0,
	CMP_POSITION = 1 << 0,
	CMP_RENDER = 1 << 1,
	CMP_COLLISION = 1 << 2 
};

#endif
