#include <stdio.h>
#include <stdlib.h>
#include "src/ghosts.h"
#include "src/movement.h"
#include "src/print.h"
#include "src/read.h"
#include <unistd.h>
#include <pthread.h>
#include "omp.h"
#include "main.h"


int map[390];


void play(Game game)
{
	omp_set_num_threads(6);
	#pragma omp parallel
	{
		Ghost *ghosts = game.ghosts;
		Pacman player = game.pac;
		int id = omp_get_thread_num();
		if(id == 4) movement(&game);
		else if (id < 4 )move_ghost(&game);
		else{
			while(player.lives!=0){
				game.printed = 0;

				printMap(&game);

				sleep(1);
				game.printed = 1;
			}
		}
	}
	
}

int main()
{
	Ghost ghosts[4];

	//Initialyze the map

	read_text("src/maps.txt", map);

	//Initialize the player

	Pacman player;
	player.pos.x = 9;
	player.pos.y = 15;
	player.lives = 3;

	//Initialyze the ghosts

	Ghost clyde, pinky, blinky, inky;

	clyde.pos.x = 9;
	clyde.pos.y = 8;
	clyde.valueLoc = 0;
	
	pinky.pos.x = 9;
	pinky.pos.y = 9;
	pinky.valueLoc = 0;

	blinky.pos.x = 9;
	blinky.pos.y = 10;
	blinky.valueLoc = 0;

	inky.pos.x = 11;
	inky.pos.y = 9;
	inky.valueLoc = 0;

	ghosts[0] = clyde;
	ghosts[1] = pinky;
	ghosts[2] = blinky;
	ghosts[3] = inky;

	//Start the game

	Game game = {player, ghosts, map,0,0};

	play(game);
	return 0;
}

