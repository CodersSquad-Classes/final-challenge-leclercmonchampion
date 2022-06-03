#include <stdio.h>
#include <stdlib.h>
#include "ghosts.h"

struct coord
{
	int x;
	int y;
};

struct pacman
{
	struct coord pos;
	int lives;
};

int main()
{
	struct pacman player;
	player.pos.x = 9;
	player.pos.y = 15;
	player.lives = 1;
	Ghost orange;
	orange.x = 9;
	orange.y = 9;
	orange = move_ghost(orange);
}

