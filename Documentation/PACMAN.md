<font color='darkorange'> PACMAN - Documentation </font>
======================

This document will allow you to understand how to build and run the program

<font color='greenyellow'> Technical Requirements : </font>
----------------------

- The game's maze layout can be static.
- The pacman gamer must be controlled by the user.
- Enemies are autonomous entities that will move a random way.
- Enemies and pacman should respect the layout limits and walls.
- Enemies number can be configured on game's start.
- Each enemy's behaviour will be implemented as a separated thread.
- Enemies and pacman threads must use the same map or game layout data structure resource.
- Display obtained pacman's scores.
- Pacman loses when an enemy touches it.
- Pacman wins the game when it has taken all coins in the map.

<font color='greenyellow'> System Requirements : </font>
----------------------

This project have been made in Golang, so you will need to: 
- Have installed Go 1.17.8 version or above
- Have installed Golang Compiler
- Use a linux distribution

We tested our program on Manjaro Linux 21.2.6


<font color='greenyellow'> Build and Run: </font>
----------------------

```
make
```

This make will allow you to compile and run the program at the same time. So you won't have to do anything else. Be careful to enter your password if it is asked during make

You will then have to select the number of ghosts you want (between 1 and 4) with the following message:

```
Choose ghosts number between 1 and 4:
```

<font color='greenyellow'> How to play Pacman ? </font>
----------------------

Following this, you will just have to take advantage of the Pacman, to move you will have to use the ZQSD keys



To look at the architecture of our project you can click [here](ARCHITECTURE.md)