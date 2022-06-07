package main

import (
	"math/rand"
	"time"
)

type ghost struct {
	x    int
	y    int
	past int
}

func moveGhosts() {
	for _, g := range Game.ghosts {
		direction := findDirection()
		g.x, g.y = Move(g.x, g.y, direction, *g)
		time.Sleep(800 * time.Millisecond)
	}
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

func Move(oldRow, oldCol int, dir string, g ghost) (newRow, newCol int) {

	newRow, newCol = oldRow, oldCol
	switch dir {
	case "UP":
		newRow = newRow - 1
		if newRow < 0 {
			newRow = len(Game.maps) - 1
		}
	case "DOWN":
		newRow = newRow + 1
		if newRow == len(Game.maps) {
			newRow = 0
		}
	case "RIGHT":
		newCol = newCol + 1
		if newCol == 19 {
			newCol = 0
		}
	case "LEFT":
		newCol = newCol - 1
		if newCol < 0 {
			newCol = 19 - 1
		}
	}

	if Game.maps[newRow*19+newCol] == '2' {
		newRow = oldRow
		newCol = oldCol
	}

	Game.maps[oldRow*19+oldCol] = g.past
	g.past = Game.maps[newRow*19+newCol]

	return
}
