#include <stdio.h>
#include "read.h"

//needs read.c to read maps.txt files to be have multiple maps
char map[418];

int printMap(char map[418]);

int main(){
    read("maps.txt", map);
    printMap(map);
    return 0;
}

int printMap(char map[418]){
    int i,j;
    for(i=0;i<22;i++){
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
                    if(i > 0) neighbors[0] = map[i-1*19+j]/2;
                    if(i < 20) neighbors[1] = map[i+1*19+j]/2;
                    if(j > 0) neighbors[2] = map[i*19+j]-1/2;
                    if(j < 18) neighbors[3] = map[i*19+j+1]/2;
                    if(neighbors[0] == 1){
                        if(neighbors[2] == 1 || neighbors[3] == 1)
                            printf(" + ");
                        else
                            printf(" | ");                    
                    }
                    else if(neighbors[1] == 1){
                        if(neighbors[2] == 1 || neighbors[3] == 1)
                            printf(" + ");
                        else 
                            printf(" | ");
                    }
                    else
                        printf("---");
            }
            
        }
        printf("\n");
        
    }
    return 0;
}