#include <stdio.h>

#ifndef SYSTEM_H
#define SYSTEM_H

#include "component.h"
#include "entity.h"

void sys_render_print_info(struct entities *_entities);

void sys_render_update(struct entities *_entities);

void sys_collision_update(struct entities *_entities);

#endif
