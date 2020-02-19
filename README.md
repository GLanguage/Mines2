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

## Thanks
Thank @itas109 for providing `./src/osplatformutil.h` (LINK)
