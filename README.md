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
- `#` if you *marked* it (as you think it is a mine)
- `X` if the mine here *exploded*
- `[0-9]f?l?` as there is/are `[0-9]` mines *around* here (`f` is shown as the *sweep-it-at-first mine* is *around* here, `l` is shown as the *sweep-it-at-last mine* is *around* here)
- `D` if the mine here has been *swept*

## Thanks
Thank [@itas109](https://github.com/itas109) for providing `./src/osplatformutil.h` ([LINK](https://github.com/itas109/OSPlatformUtil))

## Known Bugs
*NOTE: If you find any bugs, feel free to raise an issue.*
> NONE
