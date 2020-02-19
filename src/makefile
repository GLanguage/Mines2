objs = main.o game.o platform.o

main : $(objs)
	g++ -o main $(objs)

main.o : main.cpp game.h
	g++ -c main.cpp
game.o : game.cpp game.h platform.h
	g++ -c game.cpp
platform.o : platform.cpp platform.h osplatformutil.h
	g++ -c platform.cpp

.PHONY : clean
clean : 
	-rm main $(objs)