#include <stdlib.h>
#include <string.h>
#include <stdio.h>



void read_text(char m[418]){
	char ch;
	FILE *f;
	f = fopen("maps.txt","r");
	if(f==NULL){
		printf("Error opening file\n");
		exit(1);
	}
	
	int i = 0;
	while((ch=fgetc(f))!=EOF && i<418){
		if((int)ch == 48 || (int)ch==49 ||(int)ch==50){
			m[i] = ch;
			i+=1;
		}
	}

	fclose(f);
}

void print_matrix(char m[418]){
	for(size_t i = 0 ; i<22 ; i++){
        for(size_t j = 0 ; j<19 ; j++){
           printf("%c",m[i*19+j]); 
        }
        printf("\n");
    }
}

void read(char m[418]){
	read_text(char m);
    print_matrix(char m);
}