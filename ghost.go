package main

type ghost struct {
	position sprite
	status   GhostStatus
}

type sprite struct {
	row      int
	col      int
	startRow int
	startCol int
}

type GhostStatus string
