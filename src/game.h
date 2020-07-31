# ifndef GAME_H
# define GAME_H

const int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
const int dy[] = {1, -1, 0, 0, -1, -1, 1, 1};

const int BR = 10;
const int MR = 9;

int randint(int a, int b);

enum State {Hide, Show, Mark, Boom} ;

struct Point {
	State state;
	int thing; // -1 for Boom, 1~9 for numbers, 0 for nothing
	int Bkind; // 1 for First, 0 for Normal or non-Boom(or Safe), -1 for Last.
	int Nkind; // 1 for around First, 0 for Normal, -1 for around Last.
	Point();
} ;

void set(Point map[MR + 1][MR + 1]);

void view(Point map[MR + 1][MR + 1], bool colorful);

bool isout(int x, int y);

void bfs_show(Point map[MR + 1][MR + 1], int x, int y);

int input(Point map[MR + 1][MR + 1]); // 1 for done, 0 for normal, -1 for lose

int sweep(Point map[MR + 1][MR + 1]); // 1 for done, 0 for normal, -1 for lose

# endif
