#include <stdio.h>
#include <stdlib.h>
#include "src/ghosts.h"
#include "src/movement.h"
#include "src/print.h"
#include "src/read.h"
#include <unistd.h>

int score = 0;

void play(Ghost ghosts[], Pacman player)
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
	Ghost ghost[4];

	read_text("src/maps.txt", map);

	printMap(map, score);


	//initialyze the ghosts

	Ghost clyde, pinky, inky, blinky;
	ghost[0] = clyde;
	ghost[1] = pinky;
	ghost[2] = inky;
	ghost[3] = blinky;

	clyde.x = 9;
	clyde.y = 8;
	clyde.color = 'O'; //Orange
	clyde.valueLoc = 0;
	
	pinky.x = 9;
	pinky.y = 9;
	pinky.color = 'P'; //Pink
	pinky.valueLoc = 0;

	blinky.x = 9;
	blinky.y = 10;
	blinky.color = 'R'; //Red
	blinky.valueLoc = 0;

	inky.x = 11;
	inky.y = 9;
	inky.color = 'B'; //Blue
	inky.valueLoc = 0;

	//orange = move_ghost(orange);
	play(clyde);
	play(pinky);
	play(blinky);
	play(inky);
	return 0;
}

