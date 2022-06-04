#ifndef MOVEMENT_H
#define MOVEMENT_H

struct coord
{
	int x;
	int y;
};

struct pacman
{
	struct coord pos;
	int lives;
	char direction;
};

void movement(struct pacman *pacman, char direction);

#endif