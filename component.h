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
	const char* name; //this name must correspond with a name present in the sprite database;
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
	CMP_COLLISION = 1 << 2,
	CMP_INPUT_PLAYER = 1 << 3
};

#endif
