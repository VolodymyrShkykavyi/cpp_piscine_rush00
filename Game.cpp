/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:46:15 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 17:35:40 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <iostream>

#include "EnemyAsteroid.hpp"
#include <stdlib.h>

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
	if (this->yMax < 10)
	{
		std::cout << "Window too small, make it bigger!";
		endwin();
		exit(0);
	}
	this->playwin = newwin(0, 0, 0, 0);
	keypad(playwin, true);
	nodelay(playwin, true);
	player = new Player(playwin, 1, 1, '>');
	enemy = new EnemyAsteroid(this->playwin);
	done = false;
	this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
}

// addenem()
// {
// 	EnemyAsteroid enemy[50];
// 	while()
// 	{

// 	}
// }

void	Game::check_col()
{
	if ((player->getX() == enemy->getX()) && (player->getY() == enemy->getY())){
		done = true;
	while(1)
	{
		wclear(playwin);
		box(playwin, 0, 0);
		mvwprintw(playwin, 1,1, "you lose");
		wrefresh(playwin);
	}
	}

}

void	Game::start(){
	init();
	EnemyAsteroid* a = new EnemyAsteroid(this->playwin);
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
			enemy->move();
			a->move();
			check_col();
			enemy->display();
			a->display();
			// move(1, 1, "SCORE:");
			refresh();
		}
	}
	endwin();
}
