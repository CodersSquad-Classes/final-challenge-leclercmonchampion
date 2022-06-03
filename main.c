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

int main()
{
	struct pacman player;
	player.pos.x = 9;
	player.pos.y = 15;
	player.lives = 1;
	struct ghost orange;
	orange.pos.x = 9;
	orange.pos.y = 9;
	
}

