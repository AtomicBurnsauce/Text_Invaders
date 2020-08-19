#include <iostream>
#include <ncurses.h>

using namespace std;

int main()
{
	initscr();

	printw("Hello World!!!");

	refresh();

	getch(); // pause

	endwin();

	return 0;
}