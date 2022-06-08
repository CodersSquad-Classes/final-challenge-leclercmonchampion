package main

import (
	"os"
	"strconv"
	"strings"
)

func readMap(file string, map_ [399]int) ([399]int, error) {
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
			map_[i*19+j] = intN
		}
	}

	return map_, nil
}

// func that count the numbers of coins
func countCoins(map_ [399]int) int {
	coins := 0
	for _, n := range map_ {
		if n == 1 {
			coins++
		}
	}
	return coins
}
