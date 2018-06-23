/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:41:37 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 17:17:18 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <cmath>
# include <ctime>
# include <ncurses.h>
# include <sys/time.h>
# include "Player.hpp"
# include "EnemyAsteroid.hpp"
# define FPS 60

class Game
{
	int yMax, xMax;
	WINDOW * playwin;
	Player *player;
	EnemyAsteroid *enemy;
	bool done;
	clock_t t1;
	clock_t t2;
public:
	Game();
	Game(Game const &src);
	~Game();
	void	init();	
	void	start();
	void	check_col();
};

#endif