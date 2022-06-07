package main

import (
	"os"
	"strconv"
	"strings"
)

func readMap(file string, map_ []int) error []int {
	f, err := os.ReadFile(file)
	if err != nil {
		return err
	}

	lines := strings.Split(string(f), "\n")
	for i, line := range lines {
		num := strings.Split(line, ", ")
		for j, n := range num {
			intN, err := strconv.Atoi(n)
			if err != nil {
				return err
			}
			map_[i*19+j] = intN
		}

	}

	return map_
}
