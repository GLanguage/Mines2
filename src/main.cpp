//
//  main.cpp
//  Mines2
//
//  Created by Alan on 2020/2/18.
//  Copyright © 2020 Alan Han. All rights reserved.
//

# include <iostream>
# include <string>
# include "game.h"
using namespace std;

Point map[MR + 1][MR + 1];
bool colorful = true;
int main(int argc, char* argv[]) {
    if (argc >= 2 && string(argv[1]) == "--no-color") {
        colorful = false;
    }
    set(map);
    int flag = 0;
    while (flag == 0) {
        view(map, colorful);
        flag = input(map);
    }
    view(map, colorful);
    if (flag == 1)
        cout << "CONGRATULATIONS! YOU WON! " << endl;
    else
        cout << "YOU LOST. DON'T GIVE UP. TRY AGAIN. " << endl;
    return 0;
}
