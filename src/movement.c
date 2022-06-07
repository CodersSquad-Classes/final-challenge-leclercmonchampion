#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "conio.h"
#include "movement.h"
#include "struct.h"

void movement(Game *game){
    Pacman *player = &game->pac;
    int map[] = game->map;
    while(player->lives != 0){
        if(!game->printed) continue;
        map[player->pos.y*19+player->pos.x] = 0;
        if(!c_kbhit()){
            char c = c_getch();
            switch(c){
                case 'w':
                    player->direction = 'v';//going up
                    break;
                case 's':
                    player->direction = '^';//going down
                    break;
                case 'a':
                    player->direction = '<';//going right
                    break;
                case 'd':
                    player->direction = '>';//going left
                    break;
                default:
                    break;
            }
        }
        if(player->direction == '<'){
            if(player->pos.x == 0) player->pos.x = 18;
            else if (map[player->pos.y*19+player->pos.x+1] != 2) player->pos.x++;
        }
        else if(player->direction == '>'){
            if(player->pos.x == 18) player->pos.x = 0;
            else if (map[player->pos.y*19+player->pos.x-1] != 2) player->pos.x--;
        }
        else if(player->direction == '^'){
            if(player->pos.y == 20) player->pos.y = 0;
            else if (map[(player->pos.y-1)*19+player->pos.x] != 2) player->pos.y--;
        }
        else if(player->direction == 'v'){
            if(player->pos.y == 0) player->pos.y = 20;
            else if (map[(player->pos.y+1)*19+player->pos.x] != 2) player->pos.y++;
        }
        else{
            error("Invalid direction");
            return;
        }
        map[player->pos.y*19+player->pos.x] = 3;
        sleep(1);
    }
}



