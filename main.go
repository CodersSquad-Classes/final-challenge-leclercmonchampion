package main

import (
	"fmt"
	"time"
)

type Pacman struct {
	x, y    int
	lives   int
	dir     string
	changed bool
}

type Ghost struct {
	x, y    int
	past    int
	changed bool
}

type Game struct {
	pac    Pacman
	ghosts []Ghost
	maps   [399]int
	score  int
}

func main() {
	var player Pacman
	var game Game
	var maps [399]int
	var err error
	player = Pacman{9, 15, 3, "<", false}
	ghosts := []Ghost{Ghost{9, 9, 0, false}}
	game = Game{player, ghosts, maps, 0}
	game.maps, err = readMap("map.txt", game.maps)
	if err != nil {
		panic(err)
	}

	printMap(&game)

	input := make(chan string)
	go func(ch chan<- string) {
		for {
			input, err := readInput()
			if err != nil {
				ch <- "ESC"
			}
			ch <- input
		}
	}(input)

	go func() {
		for {
			moveGhosts(&game)
			time.Sleep(time.Second)
		}
	}()

	go func() {
		for {
			str := "ahag"
			select {
			case inp := <-input:
				if inp == "ESC" {
					game.pac.lives = 0
				}
				game.pac.dir = inp
				str = inp
				makeMove(&game)
			default:
			}
			game.maps[game.pac.y*19+game.pac.x] = 3
			changed := true
			for i := 0; i < len(game.ghosts); i++ {
				if !game.ghosts[i].changed {
					changed = false
					break
				}
				game.maps[game.ghosts[i].y*19+game.ghosts[i].x] = i + 4
			}

			if changed {
				printMap(&game)
				fmt.Printf("Dir: %s\n", str)
				time.Sleep(time.Second)
			}
		}

	}()
	for game.pac.lives != 0 {

	}
}
