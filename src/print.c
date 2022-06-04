#include <stdio.h>

//needs read.c to read maps.txt files to be have multiple maps

void printMap(int map[], int score){
    int i,j;
    for(i=0;i<21;i++){
        for(j=0;j<19;j++){
            int neighbors[4] = {0,0,0,0};
            switch (map[i*19+j])
            {
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf("\033[0;31m");
                    printf(" . ");
                    break;
                case 2:
                    printf("\033[0;34m");
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
                default:
                    printf("Error inf matrix format : shouldn't include %c\n", map[i*19+j]);
                    return 1;
            }
            
        }
        printf("\n");
    }
    printf("Score : %d\n", score);
}