package main

import (
	"math/rand"
	"time"
)

func moveGhosts(game *Game) {
	for i := 0; i < len(game.ghosts); i++ {
		direction := findDirection()
		game.ghosts[i].x, game.ghosts[i].y = Move(direction, &game.ghosts[i], game)
		game.maps[game.ghosts[i].y*19+game.ghosts[i].x] = i + 4
		game.ghosts[i].changed = true
	}
	time.Sleep(time.Second)
}

func findDirection() string {
	dir := rand.Intn(4)
	move := map[int]string{
		0: "UP",
		1: "DOWN",
		2: "RIGHT",
		3: "LEFT",
	}
	return move[dir]
}

func Move(dir string, ghost *Ghost, game *Game) (newRow, newCol int) {
	new_x, new_y := ghost.x, ghost.y
	switch dir {
	case "UP":
		if game.maps[(ghost.y-1)*19+ghost.x] != 2 && game.maps[(ghost.y-1)*19+ghost.x] < 4 {
			new_y--
			if new_y < 0 {
				newRow = 20
			}
		}
	case "DOWN":
		if game.maps[(ghost.y+1)*19+ghost.x] != 2 && game.maps[(ghost.y+1)*19+ghost.x] < 4 {
			new_y++
			if new_y > 20 {
				newRow = 0
			}
		}
	case "RIGHT":
		if game.maps[ghost.y*19+ghost.x+1] != 2 && game.maps[ghost.y*19+ghost.x+1] < 4 {
			new_x++
			if new_x < 0 {
				newCol = 18
			}
		}
	case "LEFT":
		if game.maps[ghost.y*19+ghost.x-1] != 2 && game.maps[ghost.y*19+ghost.x-1] < 4 {
			new_x--
			if new_x > 18 {
				newCol = 0
			}
		}
	}
	game.maps[ghost.y*19+ghost.x] = ghost.past
	ghost.past = game.maps[new_y*19+new_x]

	return new_x, new_y
}
