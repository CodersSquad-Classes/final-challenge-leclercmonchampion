package main

import (
	"fmt"
	"os"
	"time"

	"github.com/MarinX/keylogger"
)

type Pacman struct {
	x, y    int
	lives   int
	dir     string
	changed bool
	coins   int
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

var ghostsCoord = [][]int{{9, 8}, {9, 9}, {9, 10}, {11, 9}}

func main() {
	var player Pacman
	var game Game
	var maps [399]int
	var err error
	var ghostsQuantity int
	var ghosts []Ghost

	keyboard := keylogger.FindKeyboardDevice()

	k, err := keylogger.New(keyboard)
	if err != nil {
		panic(err)
	}
	defer k.Close()

	fmt.Printf("Choose ghosts number between 1 and 4: ")
	fmt.Scanf("%d", &ghostsQuantity)

	player = Pacman{9, 15, 3, "<", false, countCoins(maps)}
	for i := 0; i < ghostsQuantity; i++ {
		ghosts = append(ghosts, Ghost{ghostsCoord[i][0], ghostsCoord[i][1], 0, false})
	}
	game = Game{player, ghosts, maps, 0}
	game.maps, err = readMap("map.txt", game.maps)

	if err != nil {
		panic(err)
	}

	printMap(&game)

	input := make(chan string)
	go func(ch chan<- string) {
		events := k.Read()
		for e := range events {
			switch e.Type {

			case keylogger.EvKey:
				if e.KeyPress() {
					ch <- e.KeyString()
				}
				break

			}
		}
	}(input)

	go func() {
		for {
			makeMove(&game)
		}
	}()

	go func() {
		for {
			moveGhosts(&game)
			time.Sleep(time.Second)
			for _, ghost := range game.ghosts {
				if ghost.x == game.pac.x && ghost.y == game.pac.y {
					game.pac.x = 9
					game.pac.y = 15

					for i := 0; i < ghostsQuantity; i++ {
						ghosts = append(ghosts, Ghost{ghostsCoord[i][0], ghostsCoord[i][1], 0, false})
					}

					game.pac.lives--
					if game.pac.lives == 0 {
						os.Exit(0)
						//cas de fin de partie et de mort de pacman
					}
				}
			}
		}
	}()

	for game.pac.lives != 0 {
		str := "d"
		select {
		case inp := <-input:
			if inp == "ESC" {
				game.pac.lives = 0
				break
			}
			str = inp
			switch str {
			case "W":
				game.pac.dir = "v"
				break
			case "S":
				game.pac.dir = "^"
				break
			case "D":
				game.pac.dir = "<"
				break
			case "A":
				game.pac.dir = ">"
				break
			default:
				break
			}
		default:
		}
		game.maps[game.pac.y*19+game.pac.x] = 3
		changed := true
		for i := 0; i < len(game.ghosts); i++ {
			if !game.ghosts[i].changed {
				changed = false
				break
			}
		}

		if changed {
			printMap(&game)
			fmt.Printf("Dir: %s\n", str)
			time.Sleep(time.Second)
		}
	}
}
