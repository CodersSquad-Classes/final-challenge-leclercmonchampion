#ifndef GHOSTS_H
#define GHOSTS_H

typedef struct ghost
{
	int x;
	int y;
	char color;
	int valueLoc;
}Ghost;
Ghost move_ghost(Ghost g);

#endif
