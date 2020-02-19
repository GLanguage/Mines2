# include "platform.h"

# include "osplatformutil.h"
# include <cstdlib>
using namespace std;

# if defined(I_OS_LINUX) || defined(I_OS_UNIX) || defined(I_OS_MAC)
// Unix

// Headings
# include <unistd.h>

// Funcs
void wait(int secs) {
	sleep(secs);
}
void clear() {
	system("clear");
}

# elif defined(I_OS_WIN)
// Windows

// Headings
# include <windows.h>

// Funcs
void wait(int secs) {
	Sleep(secs * 1000);
}
void clear() {
	system("cls");
}

# endif
