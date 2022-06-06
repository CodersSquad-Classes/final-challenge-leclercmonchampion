#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "conio.h"
#include "movement.h"
#include "struct.h"

void movement(Pacman *player, int *printed){
    while(player->lives != 0){
        if(!*printed) continue;
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
            }
        }
        sleep(1);
    }
}



