/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:41:37 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/24 20:30:57 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <cmath>
# include <ctime>
# include <ncurses.h>
# include <curses.h>
# include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <string>
# include "Player.hpp"
# include "EnemyAsteroid.hpp"
#include "Shoot.hpp"
#include "EnemyShip.hpp"
#include "EnemyBoss.hpp"

# define FPS 60

class Game
{
	int yMax, xMax;
	WINDOW * playwin;
	Player *player;
	EnemyAsteroid  *enemyAsteroid[50];
	EnemyShip  	*enemyShip[50];
	EnemyBoss	*enemyBoss;
	Shoot		**playerShoots;
	Shoot		*enemyShoots[50];
	Enemy		*stars[50];
	bool done;
	clock_t t1;
	clock_t t2;
	int time;
	int points;
	int pastpoints;
public:
	Game();
	Game(Game const &src);
	Game & operator=(Game const &other);
	~Game();
	void	init();	
	void	start();
	void	check_col();
	void	add_ass();
	void	moveall();
	std::string	getTime();
	void	printLives();
	void	showEndGame();
};

#endif