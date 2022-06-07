#include "ghosts.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void move_ghost(Ghost *g, int *printed)
{
	while(1){
		if(!*printed) continue;
		int mov = rand() %2;
		int direction = rand()%2;
		g->prev.x = g->pos.x;
		g->prev.y = g->pos.y;

		switch (direction)
		{
			case 0:
				if (mov)
					g->pos.x +=1;
				else
					g->pos.x -=1;
				break;
			case 1:
				if (mov)
					g->pos.y +=1;
				else
					g->pos.y -=1;
				break;
		}
		
		sleep(1);
	}
}
