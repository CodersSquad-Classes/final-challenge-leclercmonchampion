#ifndef GHOSTS_H
#define GHOSTS_H

typedef struct ghost
{
	int x;
	int y;
	int prev_x;
	int prev_y;
	int valueLoc;
}Ghost;
void move_ghost(Ghost *g, int *printed);

#endif
