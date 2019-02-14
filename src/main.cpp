#include <curses.h>
#include <signal.h>

#include <chrono>
#include <thread>

#include "game.h"

static void finish(int sig);

int main()
{
	initscr();
	keypad(stdscr, true);
	cbreak();
	echo();

	if (has_colors()) {
		start_color();
	}

	Game g;
	auto returnVal = g.run();
	finish(returnVal);
}

static void finish(int sig)
{
	endwin();

	exit(0);
}