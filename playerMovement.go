package main

import (
	"fmt"
	"os"
)

func readInput() (string, error) {
	buffer := make([]byte, 100)

	cnt, err := os.Stdin.Read(buffer)
	if err != nil {
		return "", err
	}

	if cnt == 1 && buffer[0] == 0x1b {
		return "ESC", nil
	} else if cnt >= 3 {
		if buffer[0] == 0x1b && buffer[1] == '[' {
			switch buffer[2] {
			case 'W':
				return "v", nil // Up
			case 'S':
				return "^", nil // Down
			case 'D':
				return "<", nil // Right
			case 'Q':
				return ">", nil // Left
			}
		}
	}

	return "", nil
}

func makeMove(game *Game) {

	var player *Pacman
	var map_ *[399]int

	player = &game.pac
	map_ = &game.maps
	switch player.dir {
	case "v":
		if map_[(player.y-1)*19+player.x] != 2 {
			player.y--
			if player.y < 0 {
				player.y = 20
			}
		}

	case "^":
		if map_[(player.y+1)*19+player.x] != 2 {
			player.y++
			if player.y > 20 {
				player.y = 0
			}
		}

	case "<":
		if map_[player.y*19+player.x+1] != 2 {
			fmt.Println("aled ptn c'est de la merde")
			player.x++
			if player.x > 20 {
				player.x = 0
			}
		}

	case ">":
		if map_[player.y*19+player.x-1] != 2 {
			player.x--
			if player.x < 0 {
				player.x = 20
			}
		}

	}
}
