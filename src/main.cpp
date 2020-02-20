//
//  main.cpp
//  Mines2
//
//  Created by Alan on 2020/2/18.
//  Copyright © 2020 Alan Han. All rights reserved.
//

# include <iostream>
# include "game.h"
using namespace std;

Point map[MR + 1][MR + 1];
int main() {
    set(map);
    int flag = 0;
    while (flag == 0) {
        view(map);
        flag = input(map);
    }
    view(map);
    if (flag == 1)
        cout << "CONGRATULATIONS! YOU WON! " << endl;
    else
        cout << "YOU LOST. DON'T GIVE UP. TRY AGAIN. " << endl;
    return 0;
}
