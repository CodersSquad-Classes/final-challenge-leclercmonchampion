#ifndef GHOSTS_H
#define GHOSTS_H
/*
typedef struct
{
	int x;
	int y;
}Ghost;*/
typedef struct ghost
{
	int x;
	int y;
}Ghost;
Ghost move_ghost(Ghost g);

#endif
