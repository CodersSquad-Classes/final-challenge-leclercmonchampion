#include "ghosts.h"
#include <stdio.h>
#include <stdlib.h>
/*
struct ghost
{
	int x;
	int y;
};
*/
Ghost move_ghost(Ghost g)
{
	int mov = rand() %2;
	int direction = rand()%2;
	switch (direction)
	{
		case 0:
			if (mov)
				g.x +=1;
			else
				g.x -=1;
			break;
		case 1:
			if (mov)
				g.y +=1;
			else
				g.y -=1;
			break;
	}
	return g;
	//move_ghost(g);
}
