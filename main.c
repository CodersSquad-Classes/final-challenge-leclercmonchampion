#include <stdio.h>
#include <stdlib.h>
#include "src/ghosts.h"
#include "src/movement.h"
#include "src/print.h"
#include "src/read.h"
#include "src/struct.h"
#include <unistd.h>
#include <pthread.h>
#include "omp.h"


int map[390];
int score = 0;
int printed = 0;

void play(Game game)
{
	omp_set_num_threads(6);
	#pragma omp parallel
	{
		Ghost *ghosts = game.ghosts;
		Pacman player = game.pac;
		int id = omp_get_thread_num();
		if(id == 4) movement(&player, &printed);
		else if (id < 4 )move_ghost(&ghosts[id], &printed);
		else{
			while(player.lives!=0){
				printed = 0;
				for(int i = 0; i<4; i++){
					printf("aled\n");
					if(map[ghosts[i].pos.y*19+ghosts[i].pos.x] == 2){
						ghosts[i].pos.x = ghosts[i].prev.x;
						ghosts[i].pos.y = ghosts[i].prev.y;
					}
					else if(ghosts[i].pos.x == player.pos.x && ghosts[i].pos.y == player.pos.y){
						player.lives--;
						player.pos.x = 9;
						player.pos.y = 15;
					}
					else if(ghosts[i].pos.y > 19){
						ghosts[i].pos.y = 0;	
					}
					else if (ghosts[i].pos.y < 0){
						ghosts[i].pos.y = 18;
					}
					map[ghosts[i].prev.y*19+ghosts[i].prev.x] = ghosts[i].valueLoc;
					ghosts[i].valueLoc = map[ghosts[i].pos.y*19+ghosts[i].pos.x];
					map[ghosts[i].pos.y*19+ghosts[i].pos.x] = i+4;
				}
				if(map[player.pos.y*19+player.pos.x] == 2){
					switch (player.direction)
					{
					case 'v': //Going up
						player.pos.x -= 1;
						break;
					case 'D': //Going down
						player.pos.x += 1;
						break;
					case '>': //Going left
						player.pos.y -= 1;
						break;
					case '<': //Going right
						player.pos.y += 1;
						break;
					}
				}
				else{
					score += map[player.pos.y*19+player.pos.x]*10;
				}
				map[player.pos.y*19+player.pos.x] = 3;

				printMap(map, score, player, ghosts);

				sleep(1);
				printed = 1;
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

	Game game = {player, ghosts, map};

	play(game);
	return 0;
}

