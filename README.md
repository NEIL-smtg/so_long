# SO_LONGGGGG
A 2d game that is similar to pacman

![Gameplay in linux](https://github.com/NEIL-smtg/so_long/blob/main/demo.gif)

Compile the files and execute with the following command:
```
make && ./so_long <path_to_map>
```

You can pick any maps in the maps/ or you could just create your own map, for example:
```
make && ./so_long maps/map9.ber
```

Direction:
```
W = UP
A = LEFT
S = DOWN
D = RIGHT
```

MAP ATTRIBUTES:
```
1 = WALL
0 = WALKABLE PATH
C = COLLECTIBLE (COIN)
E = EXIT
P = PLAYER
N = ENEMY
```

# Please make sure your map is:
```
1. in .ber format
2. map has to be in rectangle shape and cover with '1' (wall)
3. At least 1 'C' (coin) and 'E' (exit)
4. Only 1 'P' (Player)
```
