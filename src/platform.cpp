# include "platform.h"

# include "osplatformutil.h"
# include <cstdlib>
# include <cstdio>
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

// Text
void marked_attr() {
	printf("\033[33m"); // yellow
}
void exploded_attr() {
	printf("\033[31m"); // red
}
void number_attr() {
	printf("\033[1m"); // bold
}
void swept_attr() {
	printf("\033[32m"); // green
}
void clear_attr() {
	printf("\033[0m");
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

// Text
void marked_attr() {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
	);
	// red + green = yellow
}
void exploded_attr() {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_RED
	);
	// red
}
void number_attr() {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
	);
	// r + g + b = white
}
void swept_attr() {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_GREEN
	);
	// green
}
void clear_attr() {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY
	);
}

# endif
