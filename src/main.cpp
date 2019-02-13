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

	std::this_thread::sleep_for(std::chrono::milliseconds(100000));

	finish(returnVal);
}

static void finish(int sig)
{
	endwin();

	exit(0);
}