# include "game.h"

# include "platform.h"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <queue>
using namespace std;

int randint(int a, int b) {
	return rand() % (b - a + 1) + a;
}

Point::Point() {
	state = Hide;
	Bkind = 0;
	thing = 0;
	Nkind = 0;
}

void set(Point map[MR + 1][MR + 1]) {
	srand((unsigned int)time(NULL));
	int mines[BR][2];
	for (int i = 0; i < BR; ) {
		int x = randint(1, 9);
		int y = randint(1, 9);
		if (map[x][y].thing == -1) {
			continue;
		}
		else {
			map[x][y].thing = -1;
			mines[i][0] = x;
			mines[i][1] = y;
			i++;
		}
	}
    int fm, lm;
	fm = randint(0, BR - 1);
    do
        lm = randint(0, BR - 1);
    while (lm == fm);
	map[mines[fm][0]][mines[fm][1]].Bkind = 1;
	map[mines[lm][0]][mines[lm][1]].Bkind = -1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (map[i][j].thing == -1) {
				continue;
			}
			for (int d = 0; d < 8; d++) {
				Point neighbor = map[i + dx[d]][j + dy[d]];
				if (neighbor.thing == -1) {
					map[i][j].thing++;
					if (neighbor.Bkind == 1) {
						map[i][j].Nkind = 1;
					}
					if (neighbor.Bkind == -1) {
						map[i][j].Nkind = -1;
					}
				}
			}
		}
	}
}

void view(Point map[MR + 1][MR + 1], bool colorful) {
	clear();
    cout << " \t";
    for (int j = 1; j <= 9; j++) {
        cout << j << '\t';
    }
    cout << endl << endl;
	for (int i = 1; i <= 9; i++) {
        cout << i << '\t';
		for (int j = 1; j <= 9; j++) {
			switch (map[i][j].state) {
				case Show:
                    if (map[i][j].thing == -1) {
                        if (colorful) swept_attr();
                        cout << "D\t";
                        break;
                    }
                    if (colorful) number_attr();
					cout << map[i][j].thing;
					if (map[i][j].Nkind == 1) {
						cout << 'f';
					}
					if (map[i][j].Nkind == -1) {
						cout << 'l';
					}
					cout << '\t';
					break;
				case Mark:
                    if (colorful) marked_attr();
					cout << "#\t";
					break;
				case Boom:
                    if (colorful) exploded_attr();
					cout << "X\t";
					break;
				default:
					cout << "N\t";
			}
            clear_attr();
		}
		cout << endl << endl;
	}
}

bool isout(int x, int y) {
    return (x > 9 || x < 1 || y > 9 || y < 1);
}

void bfs_show(Point map[MR + 1][MR + 1], int x, int y) {
	if (isout(x, y)) {
		return;
	}
	if (map[x][y].state == Show || map[x][y].thing == -1) {
		return;
	}
	if (map[x][y].thing > 0)
	{
		map[x][y].state = Show;
		return;
	}
    queue<int> q;
    q.push(x * 10 + y); // AMAZING!
    while (!q.empty()) {
        int t = q.front();
        int tx = t / 10;
        int ty = t % 10;
        map[tx][ty].state = Show;
        for (int d = 0; d < 8; d++) {
            int nx = tx + dx[d];
            int ny = ty + dy[d];
            if (isout(nx, ny)) {
                continue;
            }
            if (map[nx][ny].state == Show || map[nx][ny].thing == -1) {
                continue;
            }
            if (map[nx][ny].thing > 0) {
                map[nx][ny].state = Show;
                continue;
            }
            q.push(nx * 10 + ny);
        }
        q.pop();
    }
}

int input(Point map[MR + 1][MR + 1]) {
    int mark; // 1 for marking, 0 for showing, -1 for sweeping
    cin >> mark;
    if (mark == -1) {
        return sweep(map);
    }
    else {
        int x, y;
        cin >> x >> y;
        if (mark == 1) {
            if (map[x][y].state == Hide) {
                map[x][y].state = Mark;
            }
            else if (map[x][y].state == Mark) {
                map[x][y].state = Hide;
            }
        }
        else {
            if (map[x][y].thing == -1) {
                map[x][y].state = Boom;
                return -1;
            }
            bfs_show(map, x, y);
        }
    }
    return 0;
}

int sweep(Point map[MR + 1][MR + 1]) {
    bool fswd = false;
    bool lswd = false;
    bool done = true;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (map[i][j].state == Mark) {
                map[i][j].state = Show;
            }
            fswd |= (map[i][j].Bkind == 1 && map[i][j].state == Show);
            lswd |= (map[i][j].Bkind == -1 && map[i][j].state == Show);
            done &= (map[i][j].thing != -1 || map[i][j].state == Show);
        }
    }
    if (!fswd) {
        return -1;
    }
    if (done) {
        return 1;
    }
    else if (lswd) {
        return -1;
    }
    else {
        return 0;
    }
    return 0;
}
