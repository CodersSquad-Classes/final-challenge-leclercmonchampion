#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void read_text(char *filename, char *m[]){
	char ch;
	FILE *f;
	f = fopen(filename, "r");
	if(f==NULL){
		printf("Error opening file\n");
		exit(1);
	}

	int i=0;
	while((ch=fgetc(f))!=EOF){
		if((int)ch==48 || (int)ch==49 || (int)ch==50){
			*m[i]=ch;
			i++;
		}
	}
	fclose(f);
}

void print_matrix(char *m[]){
	for(size_t i = 0 ; i<22 ; i++){
        for(size_t j = 0 ; j<19 ; j++){
           printf("%c", *m[i*19+j]); 
        }
        printf("\n");
    }
}

char* read(char *filename){
	char *m[418];
	read_text(filename, m);
	print_matrix(m);
	return *m;
}
