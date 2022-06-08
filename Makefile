CC=go build


all:
	$(CC) main.go playerMovement.go read.go print.go ghost.go
	sudo ./main

clean:
	rm -f main

