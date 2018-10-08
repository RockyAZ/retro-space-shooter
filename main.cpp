#include "retro.hpp"
#include <fstream>
namespace	w
{
	int		width;
	int		height;
	int		gameLoop = 1;
	int		i;
	int		i1;
	long int score = 0;
}

namespace	obj
{
	I		h(3, 3);
	Bullet	b[300];
	Enemy	e[150];
}

namespace	t
{
	clock_t	t0;
}

void		controls(int key, int h, int w)
{
	switch(key)
	{
		case KEY_LEFT:
			obj::h.setX(-1);
			if (obj::h.getX() - 1 < 0)
				obj::h.setX(1);
			obj::h.display();
			break ;
		case KEY_RIGHT:
			obj::h.setX(1);
			if (obj::h.getX() > w / 4)
				obj::h.setX(-1);
			obj::h.display();
			break ;
		case KEY_UP:
			obj::h.setY(-1);
				if (obj::h.getY() - 1 < 0)
					obj::h.setY(1);
			obj::h.display();
			break ;
		case KEY_DOWN:
			obj::h.setY(1);
			if (obj::h.getY() > h - 5)
				obj::h.setY(-1);
			obj::h.display();
			break ;
		case 27:
			w::gameLoop = 0;
			break ;
		case 32:
			w::i = ++w::i % 150;
			obj::b[w::i] = Bullet(obj::h.getX(), obj::h.getY());
			break ;
		}
}

void		display_health(clock_t tStart)
{
	mvprintw(w::height - 1,0, "health:");
	mvprintw(w::height - 2,0, "SCORE:");
	mvprintw(w::height - 3,0, "Time:");
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvaddch(w::height - 1, 7, ACS_DIAMOND);
	mvprintw(w::height - 2, 7, "%d", w::score);
	mvprintw(w::height - 3, 7, "%f", double((clock() - tStart)/CLOCKS_PER_SEC));
	attroff(COLOR_PAIR(1));
}

void	check(int w)
{
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 150; j++)
		{
			if ( (obj::b[i].getX() - obj::e[j].getX()) > -3 && (obj::b[i].getX() - obj::e[j].getX()) <= 0  && obj::b[i].getY() == obj::e[j].getY())
			{
				obj::b[i].setX(w);
				obj::e[j].setX(-40000);
				w::score++;
				if (w::score > 500)
					w::gameLoop = 0;
			}
			if (obj::h.getX() == obj::e[j].getX() && obj::h.getY() == obj::e[j].getY())
				w::gameLoop = 0;
		}
}

int			main(void)
{
	clock_t tStart = clock();
	srand(time(NULL));
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	cbreak();
	nodelay(stdscr, true);
	getmaxyx(stdscr, w::height, w::width);


	start_color();
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(3));
		for (int j = 0; j < w::height; j++)
				mvaddch(j, w::width / 2, ')');
	attroff(COLOR_PAIR(3));

	int var;
	for(int i = 0; i < 150; i++)
	{
		var = i;
		while (var > w::height)
			var = var - w::height;
		obj::e[i].setY(std::abs(var));
	}
	w::i = -1;
	while (w::gameLoop)
	{
		for (int i = 0; i < w::width; i++)
			for (int j = 0; j < w::height; j++)
				if ((char)mvinch(j, i) != ')')
				mvaddch(j, i, ' ');
	if(!((int((clock() - tStart)/CLOCKS_PER_SEC)) % 5))
	{
		start_color();
		init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
		attron(COLOR_PAIR(3));
			for (int j = 0; j < w::height; j++)
					mvaddch(j, w::width / 2, ')');
		attroff(COLOR_PAIR(3));
	}

		// erase();
		t::t0 = clock();
		w::i1 = 0;
		while (w::i1 <= w::i && w::i1 < 150)
		{
		int random = std::rand() % 150;
		if (obj::e[random].getX() <= 0)
		{
		obj::e[random].setX(w::width);
		}
			obj::b[w::i1].update();
			obj::e[w::i1].update();
			w::i1++;
		}
		check(w::width);
		obj::h.display();
		display_health(tStart);
		controls(getch(), w::height, w::width);
		while (clock() - t::t0 <  20000){};
	}
	endwin();
	std::cout << "GAME OVER!" << std::endl;
	if (w::score > 500)
		std::cout << "YOU WIN!!!" << std::endl;
	return 0;
}
