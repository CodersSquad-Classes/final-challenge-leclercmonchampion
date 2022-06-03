#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int _kbhit();

int main(){
    WINDOW *menu_win;
    char c ;

    cbreak();
    int startx = (80 - WIDTH) / 2;
	int starty = (24 - HEIGHT) / 2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);	

    while(1)
	{	c = wgetch(menu_win);
		printf("%d\n", c);
	}	
    return 1;
}

