/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:19:13 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 13:41:05 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

int	main(){
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * playwin = newwin(0, 0, 0, 0);
	box(playwin, 0, 0);
	refresh();
	wrefresh(playwin);

	Player * p = new Player(playwin, 1, 1, '>');
	while(p->getmv() != 'x')
	{
		p->display();
		wrefresh(playwin);
	}

	endwin();
	delete p;
	return 0;
}
