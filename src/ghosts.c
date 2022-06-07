#include "ghosts.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "struct.h"
#include "../main.h"

#define UP map[ghosts[i].pos.y*19+ghosts[i].pos.x-1]
#define DOWN map[ghosts[i].pos.y*19+ghosts[i].pos.x+1]
#define LEFT map[(ghosts[i].pos.y-1)*19+ghosts[i].pos.x]
#define RIGHT map[(ghosts[i].pos.y+1)*19+ghosts[i].pos.x]

void move_ghost(Game *game)
{
	Ghost *ghosts = game->ghosts;
	Pacman player = game->pac;
	while(player.lives!=0){
			if(!game->printed) continue;
			for(int i = 0; i<4; i++){
				int dir = rand()%4;
				switch (dir)
				{
					case 0: //Going up
						if(UP <= 1 || UP == 3) ghosts[i].pos.x -= 1;
						break;
					case 1: //Going down
						if(DOWN <= 1 || DOWN == 3) ghosts[i].pos.x += 1;
						break;
					case 2: //Going left
						if(LEFT <= 1 || LEFT == 3) ghosts[i].pos.y -= 1;
						break;
					case 3: //Going right
						if(RIGHT <= 1 || RIGHT == 3) ghosts[i].pos.y += 1;
						break;
					default:
						break;

				}
				if(ghosts[i].pos.x == player.pos.x && ghosts[i].pos.y == player.pos.y){
					player.lives--;
					player.pos.x = 9;
					player.pos.y = 15;
				}
				else if(ghosts[i].pos.y > 20){
					ghosts[i].pos.y = 0;	
				}
				else if (ghosts[i].pos.y < 0){
					ghosts[i].pos.y = 20;
				}
				else if(ghosts[i].pos.x > 18){
					ghosts[i].pos.x = 0;
				}
				else if(ghosts[i].pos.x < 0){
					ghosts[i].pos.x = 18;
				}
				map[ghosts[i].prev.y*19+ghosts[i].prev.x] = ghosts[i].valueLoc;
				ghosts[i].valueLoc = map[ghosts[i].pos.y*19+ghosts[i].pos.x];
				map[ghosts[i].pos.y*19+ghosts[i].pos.x] = i+4;
			}		
			sleep(1);
		}
	}
}
