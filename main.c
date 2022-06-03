#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct coord
{
	int x;
	int y;
};

struct ghost
{
	struct coord pos;
};

struct pacman
{
	struct coord pos;
	int lives;
};

void move_ghost(struct ghost g)
{
	int mov = rand() %2;
	int direction = rand() %2;
	//printf("mov %d, direct %d\n",mov,direction);
	switch (direction)
	{
		case 0:
			if (mov)
				g.pos.x +=1;
			else
				g.pos.x -=1;
			break;
		case 1:
			if (mov)
				g.pos.y +=1;
			else
				g.pos.y -=1;
			break;
	}
	//printf("(%d,%d)\n", g.pos.x,g.pos.y);
	sleep(1);
	move_ghost(g);
}

int main()
{
	/*struct pacman player;
	player.pos.x = 9;
	player.pos.y = 15;
	player.lives = 1;*/
	struct ghost orange;
	orange.pos.x = 9;
	orange.pos.y = 9;
	move_ghost(orange);
}

