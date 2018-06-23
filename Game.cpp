/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:46:15 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 16:53:39 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <iostream>

#include "EnemyAsteroid.hpp"

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
	keypad(playwin, true);
	nodelay(playwin, true);
	player = new Player(playwin, 1, 1, '>');
	done = false;
	this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
}

void	Game::start(){
	init();
	while(!done)
	{
		getmaxyx(playwin, this->yMax, this->xMax);
		this->t1 = clock() / (CLOCKS_PER_SEC / FPS);
		if (this->t1 > this->t2)
		{
			this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
			player->getmv(yMax, xMax);
			wclear(playwin);
			player->display();
			box(playwin, 0, 0);
			EnemyAsteroid *enemy = new EnemyAsteroid(this->playwin);
			enemy->display();
			refresh();
		}
	}

	endwin();
}
