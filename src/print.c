#include <stdio.h>
#include "conio.h"
#include "struct.h"

//needs read.c to read maps.txt files to be have multiple maps

void printMap(Game *game){
    int i,j;
    Pacman player = game->pac;
    int map[] = game->map;
    printf("\033[2J\033[1;1H");
    for(i=0;i<21;i++){
        for(j=0;j<19;j++){
            int neighbors[4] = {0,0,0,0};
            switch (map[i*19+j])
            {
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf("\x1b[31;1m");
                    printf(" . ");
                    break;
                case 2:
                    printf("\x1b[34m");
                    if(i > 0) neighbors[0] = map[(i-1)*19+j];
                    if(i < 20) neighbors[1] = map[(i+1)*19+j];
                    if(j > 0) neighbors[2] = map[i*19+j-1];
                    if(j < 18) neighbors[3] = map[i*19+j+1];
                    if(neighbors[0] == 2){
                        if(neighbors[2] == 2 || neighbors[3] == 2)
                            printf(" + ");
                        else
                            printf(" | ");                    
                    }
                    else if(neighbors[1] == 2){
                        if(neighbors[2] == 2 || neighbors[3] == 2)
                            printf(" + ");
                        else 
                            printf(" | ");
                    }
                    else{
                        if(j == 0 || j == 18)
                            printf(" + ");
                        else
                            printf("---");

                    }
                        
                    break;
                case 3:
                    printf("\x1b[33;1m");
                    printf(" %c ", player.direction);
                    break;
                case 4: //clyde
                    c_textcolor(12); //Light red
                    printf(" %c ", 'n');
                    break;
                case 5: //pinky
                    c_textcolor(12); //light magenta
                    printf(" %c ", 'n');
                    break;
                case 6: //blinky
                    c_textcolor(12); //light yellow
                    printf(" %c ", 'n');
                    break;
                case 7: //inky
                    c_textcolor(12); //light cyan
                    printf(" %c ", 'n');
                    break;
                default:
                    printf("Error inf matrix format : shouldn't include %c\n", map[i*19+j]);
                    return;
            }
            
        }
        printf("\n");
    }
    printf("Score : %d\n", game->score);
}