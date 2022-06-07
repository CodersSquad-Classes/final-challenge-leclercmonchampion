package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Pacman struct {
	pos_x, pos_y int
	lives        int
	direction    string
}

type Game struct {
	pac  Pacman
	maps []int
	score int
}

func printMap(g *Game) {

	player Pacman := game.pac
	map[] int := game.maps

	fmt.Prinln("\033[2J\033[1;1H")
	for i := 0; i < 21; i++ {
		for j := 0; j < 19; j++ {
			neighbor[4] int := {0,0,0,0}
			switch (map[i*19+j]) {
			case 0:
				fmt.Print("   ")
			case 1:
				fmt.Print("\x1b[31;1m")
				fmt.Print(" . ")
			case 2:
				fmt.Print("\x1b[34m")
				if i>0{
					neighbor[0] = map[(i-1)*19+j]
				}
				if i<20{
					neighbor[1] = map[(i+1)*19+j]
				}
				if j>0{
					neighbor[2] = map[i*19+j-1]
				}
				if j<18{
					neighbor[3] = map[i*19+j+1]
				}

				if neighbor[0] == 2{
					if neighbor[2] == 2 || neighbor[3] == 2 {
						fmt.Print(" + ")
					}
					else{
						fmt.Printf(" | ")
					}
				}
				else if neighbor[1] == 2{
					if neighbor[2] == 2 || neighbor[3] == 2 {
						fmt.Print(" + ")
					}
					else{
						fmt.Print(" | ")
					}
				
				else{
					if j==0 || j==18 {
						fmt.Print(" + ")
					}
					else{
						fmt.Print("---")
					}
				}
			case 3:
				fmt.Print("\x1b[33;1m")
				fmt.Print(player.direction)
			case 4:
				fmt.Print("n")
			case 5:
				fmt.Print("n")
			case 6:
				fmt.Print("n")
			case 7:
				fmt.Print("n")
			default:
				fmt.Print("Error inf matrix format")
			}
			}
		}
	fmt.Print("\n")
	}
	fmt.Print(game.score)
}
