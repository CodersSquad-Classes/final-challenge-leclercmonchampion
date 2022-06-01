#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char m[418];

void read_text(){
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

void print_matrix(){
	for(size_t i = 0 ; i<9 ; i++){
        for(size_t j = 0 ; j<9 ; j++){
           printf("%c",m[i*9+j]); 
        }
        printf("\n");
    }
}

int main(){
	read_text();
    print_matrix();
}

