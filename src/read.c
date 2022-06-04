#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void read_text(char *filename, int m[]){
	int ch;
	FILE *f;
	f = fopen(filename, "r");
	if(f==NULL){
		printf("Error opening file\n");
		exit(1);
	}

	int i=0;
	while((ch=fgetc(f))!=EOF){
		if((int)ch==48 || (int)ch==49 || (int)ch==50){
			m[i]=ch-48;
			i++;
		}
	}
	fclose(f);
}

void print_matrix(int m[]){
	for(size_t i = 0 ; i<21 ; i++){
        for(size_t j = 0 ; j<19 ; j++){
           printf("%c", m[i*19+j]+48); 
        }
        printf("\n");
    }
}

void readBis(char *filename, int m[]){
	read_text("maps.txt", m);
	print_matrix(m);
}





