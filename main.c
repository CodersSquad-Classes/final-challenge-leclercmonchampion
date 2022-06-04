#include <stdio.h>
#include <stdlib.h>
#include "src/ghosts.h"
#include "src/movement.h"
#include "src/print.h"
#include "src/read.h"
#include <unistd.h>

int score = 0;

void play(Ghost g)
{
	printf("(%d, %d)\n",g.x,g.y);
	g = move_ghost(g);
	sleep(1);
	play(g);
}

int main()
{
	/*struct pacman player;
	player.pos.x = 9;
	player.pos.y = 15;
	player.lives = 1;*/
	int map[390];

	read("src/maps.txt", map);

	printMap(map, score);

	Ghost orange;
	orange.x = 9;
	orange.y = 9;
	//orange = move_ghost(orange);
	play(orange);
	return 0;
}

