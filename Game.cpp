/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:46:15 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 14:26:17 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(){}

Game::Game(Game const &src){
	*this = src;
}

Game::~Game(){}

void	Game::init(){
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->playwin = newwin(0, 0, 0, 0);
	wrefresh(playwin);
	player = new Player(playwin, 1, 1, '>');
}

void	Game::start(){
	init();
	while(player->getmv(yMax, xMax) != 'x')
	{
		getmaxyx(playwin, this->yMax, this->xMax);
		player->display();
		wrefresh(playwin);
		box(playwin, 0, 0);
		refresh();
	}
	endwin();
}
