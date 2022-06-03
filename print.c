#include <stdio.h>
#include "read.h"

//needs read.c to read maps.txt files to be have multiple maps
int map[418];

int printMap();

int main(){
    read("maps.txt", map);
    printMap();
    return 0;
}

int printMap(){
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
                    if(i > 0) neighbors[0] = map[i-1*19+j];
                    if(i < 20) neighbors[1] = map[i+1*19+j];
                    if(j > 0) neighbors[2] = map[i*19+j]-1;
                    if(j < 18) neighbors[3] = map[i*19+j+1];
                    if(neighbors[0] == 1){
                        if(neighbors[2] == 2 || neighbors[3] == 2)
                            printf(" + ");
                        else
                            printf(" | ");                    
                    }
                    else if(neighbors[1] == 1){
                        if(neighbors[2] == 1 || neighbors[3] == 2)
                            printf(" + ");
                        else 
                            printf(" | ");
                    }
                    else
                        printf("---");
                    break;
                /*default:
                    printf("Error inf matrix format : shouldn't include %c", map[i*19+j]);
                    break;*/
            }
            
        }
        printf("\n");
        
    }
    return 0;
}