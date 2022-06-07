#ifndef MAIN_H
#define MAIN_H

struct coord
{
	int x;
	int y;
};

typedef struct Pacman
{
	struct coord pos;
	int lives;
	char direction;
}Pacman;

typedef struct Ghost
{
    struct coord prev;
    struct coord pos;
	int valueLoc;
}Ghost;

typedef struct Game{
    Pacman pac;
    Ghost *ghosts;
	int *map;
	int score;
	int printed;
}Game;


int map[390];
void play(Game game);
int main();



#endif
