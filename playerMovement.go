package main

import (
	"os"
	"time"
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
			case 'w':
				return "v", nil // Up
			case 's':
				return "^", nil // Down
			case 'd':
				return "<", nil // Right
			case 'q':
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

	x, y := player.x, player.y

	changed := false

	switch player.dir {
	case "v":
		if map_[(player.y-1)*19+player.x] != 2 {
			player.y--

			if player.y < 0 {
				player.y = 20
			}
			changed = true
		}

	case "^":
		if map_[(player.y+1)*19+player.x] != 2 {
			player.y++
			if player.y > 20 {
				player.y = 0
			}
			changed = true
		}

	case "<":
		if map_[player.y*19+player.x+1] != 2 {
			player.x++
			if player.x > 20 {
				player.x = 0
			}
			changed = true
		}

	case ">":
		if map_[player.y*19+player.x-1] != 2 {
			player.x--
			if player.x < 0 {
				player.x = 20
			}
			changed = true
		}

	}

	if changed {
		map_[y*19+x] = 0
	}
	if map_[player.y*19+player.x] == 1 {
		game.score += 10
		game.coins--
	}

	// check is coins are over
	if game.coins == 1 {
		print("You win!")
		os.Exit(0)
	}

	time.Sleep(time.Second)
}
