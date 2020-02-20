# Mines2
A new mine-sweeping game.

## Dependencies
- `g++` (GNU)
- `make` (GNU) (optional)

## Usage
### Linux / Unix / Mac OS
After cloning the repo, `cd` into the `./src` directory, and run
```shell
$ g++ -c main.cpp
$ g++ -c game.cpp
$ g++ -c platform.cpp
$ g++ -o main main.o game.o platform.o
```
or (with GNU make)
```shell
$ make
```
Then, to start the game, run
```shell
$ ./main
```
*NOTE: The process will end automatically after the game is over (you win or lose) . To quit the game befor it is over, press **Ctrl+C**.*  
To uninstall the game, run
```shell
$ rm main main.o game.o platform.o
```
or (with GNU make)
```shell
$ make clean
```
The executable file and the object files (`*.o`) will be removed.
### Windows
After cloning the repo, `cd` into the `./src` directory, and run
```shell
$ g++ -c main.cpp
$ g++ -c game.cpp
$ g++ -c platform.cpp
$ g++ -o main.exe main.obj game.obj platform.obj
```
Then, to start the game, run
```shell
$ main.exe
```
*NOTE: The process will end automatically after the game is over (you win or lose) . To quit the game befor it is over, press **Ctrl+C**.*  
To uninstall the game, run
```shell
$ del main.exe main.obj game.obj platform.obj
```
The executable file and the object files (`*.obj`) will be removed.  
If you want to build and/or uninstall the game through GNU make on a Windows OS, replace the commands inside the `./src/makefile` by
```make
objs = main.obj game.obj platform.obj

main.exe : $(objs)
	g++ -o main.exe $(objs)

main.obj : main.cpp game.h
	g++ -c main.cpp
game.obj : game.cpp game.h platform.h
	g++ -c game.cpp
platform.obj : platform.cpp platform.h osplatformutil.h
	g++ -c platform.cpp

.PHONY : clean
clean : 
	-del main.exe $(objs)
```
Then you can build the game by running
```shell
$ make
```
and uninstall it by running
```shell
$ make clean
```

## How to Play
### Beginning
The game begins with a 9 * 9 map:
```
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
N	N	N	N	N	N	N	N	N	
```
The map is full of `N`. `N` means that it is *unknown* (aka *Hided*) . Later, `N` may be replaced by
- `#` if it is *marked* (as you think it is a mine)
- `X` if the mine here *exploded*
- `[0-9]f?l?` if the position is *shown* and there is/are `[0-9]` mines *around* here (`f` is shown as the *sweep-it-at-first mine* is *around* here; `l` is shown as the *sweep-it-at-last mine* is *around* here)
- `D` if the mine here has been *swept*
### Checking
For any *unknown* position P(x, y), if you *believe* it *is not* a mine, you can *check* it (make it *shown*) by entering
```
0 x y
```
0 means checking, and x, y show the position of P.  
After entering, if P is *not* a mine, it will turn to `[0-9]f?l?`, showing the number of mines around P. *Otherwise*, it will turn to `X` and the game will be over (with `YOU LOST. ...` printed) .
### Marking
For any *unknown* position P(x, y), if you *believe* it *is* a mine, you can *mark* it (to be *swept* later) by entering
```
1 x y
```
1 means marking, and x, y show the position of P.  
After entering, P will turn to `#`.
### Sweeping
You can *sweep* all the *marked* positions by entering
```
-1
```
After entering, for each one of the *marked* positions, if it *is* a mine, it will turn to `D`. *Otherwise*, it will turn to `[0-9]f?l?` (*shown*) .  
If you swept all the mines, the game will be over (with `... YOU WON! ` printed) .  
*NOTE: After sweeping, the game may be over (you win or lose). For further information, see SIAF & SIAL.*
### SIAF & SIAL
The SIAF (sweep-it-at-first) mine and the SIAL (sweep-it-at-last) mine are the special mines in *Mines2*.  

## Thanks
Thank [@itas109](https://github.com/itas109) for providing `./src/osplatformutil.h` ([LINK](https://github.com/itas109/OSPlatformUtil))

## Known Bugs
*NOTE: If you find any bugs, feel free to raise an issue.*
> NONE
