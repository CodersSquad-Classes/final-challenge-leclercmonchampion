package main

import "fmt"

type Pacman struct {
	x, y  int
	lives int
	dir   string
}

type Game struct {
	pac   Pacman
	maps  [399]int
	score int
}

func main() {
	var player Pacman
	var game Game
	var maps [399]int
	var err error
	player = Pacman{9, 15, 3, ">"}
	game = Game{player, maps, 0}
	game.maps, err = readMap("map.txt", game.maps)
	if err != nil {
		panic(err)
	}

	printMap(&game)
	fmt.Print("b")

	movements := make(chan string)
	go func(ch chan<- string) {
		fmt.Print("c")
		for {
			fmt.Print("a")
			readInput()
			makeMove(&game)
		}
	}(movements)

}
