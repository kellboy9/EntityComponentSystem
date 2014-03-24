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
	float x;
	float y;
	float w;
	float h;
	//SDL_Surface* sprite;
};

#endif
