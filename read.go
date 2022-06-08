package main

import (
	"os"
	"strconv"
	"strings"
)

func readMap(file string, map_ [399]int, game *Game) ([399]int, error) {
	f, err := os.ReadFile(file)

	if err != nil {
		return map_, err
	}

	lines := strings.Split(string(f), "\n")
	for i, line := range lines {
		num := strings.Split(line, ",")
		for j, n := range num {
			intN, err := strconv.Atoi(n)
			if err != nil {
				return map_, err
			}
			if intN == 1 {
				game.coins++
			}
			map_[i*19+j] = intN
		}
	}

	return map_, nil
}
