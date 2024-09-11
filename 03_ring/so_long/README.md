[**Results in this milestone**](https://github.com/zikocult/Cursus42/tree/main/03_ring)

This project is a very small 2D game. Its purpose is to make me work with textures, sprites, and some other very basic gameplay elements.

Being a developer is a great thing for creating your own game.

It’s time for to create a basic computer graphics project!

So long will help me to improve your skills in the following areas: window management, event handling, colors, textures, and so forth.

I am going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

The other goals are similar to every other goal for this first year: being rigorous, level up in C programming, use basic algorithms, do some information research, and so forth.

The works with w, a, s, d or the arrow keys, you can finish the game pressing the ESC key, and the rules are very simple, you are a samurai collect all the bottles, avoid the enemies and scape to the door.

![[Pasted image 20240911124224.png]]

If you want to test it, you can clone this repository and simply execute make, this will compile all for you, and you only need to execute the program and for the arguments send the map of your choice:

```bash
./so_long maps/bonus/map2.ber
```

You can create your own maps, but with certain norms that are validated:
- The map can be composed with the next characters:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit
	- P for a player's starting position
	- X for an enemy
- The map must contain at least 1 collectible, 1 starting position and 1 exit.
- The map mus be rectangular
- Must be closed / surrounded by walls.
- Is checked if there's a valid path in the map.

Here is a simple valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
111111111111
```

My map collection is added to this repository, included the error maps.