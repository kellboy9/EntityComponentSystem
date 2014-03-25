#include <stdio.h>
#include "entity.h"
#include "component.h"
#include "system.h"


int main(int argc, char** argv)
{
	//ENTITY_COUNT 500
	printf("%d\n", ENTITY_COUNT);
	struct entities entities;
	create_player(&entities, 5.0f, 10.0f);		
	create_entity(&entities);
	create_player(&entities, 10.0f, 5.0f);
	sys_render_print_info(&entities);
	return 0;
}
