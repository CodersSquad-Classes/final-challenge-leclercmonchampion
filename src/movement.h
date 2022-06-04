#ifndef MOVEMENT_H
#define MOVEMENT_H

struct coord
{
	int x;
	int y;
};

typedef struct Pacman
{
	struct coord pos;
	int lives;
	char direction;
}Pacman;

void movement(Pacman *pacman);

#endif