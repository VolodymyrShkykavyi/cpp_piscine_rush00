/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:49:25 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 20:43:36 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>
#include <sys/time.h>
#include "Shoot.hpp"
class Player
{
	int xLoc_, yLoc_, xMax_, yMax_;
	char player_;
	WINDOW *curwin_;
    Shoot * _shoots[100];
    int _lives;
    bool _immortal;

public:
	Player();
	Player(WINDOW *win, int y, int x, char c);
	Player(Player const &src);
	~Player();

    int	    getX();
	int     getY();
	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	int getmv(int y, int x);
	bool getImmortal();
	void setImmortal(bool val);
	int getLives();
	void removeLive();
	void display();
    void    shoot();
    Shoot ** getShoots();

};

#endif