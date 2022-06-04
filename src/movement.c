#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "conio.h"
#include "movement.h"

#define true 1

void movement(Pacman *player){
    while(true){
        if(!c_kbhit()){
            char c = c_getch();
            switch(c){
                case 'w':
                    (*player).direction = 'U';//going up
                    break;
                case 's':
                    (*player).direction = 'D';//going down
                    break;
                case 'a':
                    (*player).direction = 'U';//going right
                    break;
                case 'd':
                    (*player).direction = 'U';//going left
                    break;
            }
        }
    }
}



