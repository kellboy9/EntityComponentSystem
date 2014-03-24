#include <stdio.h>
#include "entity.h"

int main(int argc, char** argv)
{
	int num_entities = 5;
	struct entity entities[num_entities];
	int i;
	for(i = 0; i < num_entities; ++i)
	{
		entities[i].id = i;
	}
	
	for(i = 0; i < num_entities; ++i)
	{
		printf("%d\n", entities[i].id);
	}
	return 0;
}
