/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:49:39 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 17:16:09 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

Player::Player(){}

Player::Player(WINDOW *win, int y, int x, char c){
	curwin_ = win;
	yLoc_ = y;
	xLoc_ = x;
	getmaxyx(curwin_, yMax_, xMax_);
	keypad(curwin_, true);
	player_ = c;

    for (int i; i < 100; i++) {
        this->_shoots[i] = new Shoot(this->curwin_, this->yLoc_, this->xLoc_, 1);
    }
}

Player::Player(Player const &src){
	*this = src;
}

Player::~Player(){
   // delete [] this->_shoots;
}

void Player::mvup(){
	mvwaddch(curwin_, yLoc_, xLoc_, ' ');
	yLoc_--;
	if (yLoc_ < 1)
		yLoc_ = 1;
}

void Player::mvdown(){
	mvwaddch(curwin_, yLoc_, xLoc_, ' ');
	yLoc_++;
	if (yLoc_ > yMax_-2)
		yLoc_ = yMax_-2;
}

void Player::mvleft(){
	mvwaddch(curwin_, yLoc_, xLoc_, ' ');
	xLoc_--;
	if(xLoc_ < 1)
		xLoc_ = 1;
}

void Player::mvright(){
	mvwaddch(curwin_, yLoc_, xLoc_, ' ');
	xLoc_++;
	if (xLoc_ > xMax_-2)
		xLoc_ = xMax_-2;
}

void    Player::shoot()
{
    for (int i = 0; i < 100; ++i) {
        if (this->_shoots[i]->getAlive() == false) {
            this->_shoots[i]->setAlive(true);
            this->_shoots[i]->setX(this->xLoc_);
            this->_shoots[i]->setY(this->yLoc_);
            break;
        }
    }
}

int Player::getmv(int y, int x){
	int choice = wgetch(curwin_);
	this->yMax_ = y;
	this->xMax_ = x;
	switch(choice)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
        case ' ':
            this->shoot();
            break;
		default:
			break;
	}
	return choice;
}

void Player::display(){
	mvwaddch(curwin_, yLoc_, xLoc_, player_);
}

int		Player::getX()
{
	return this->xLoc_;
}

int		Player::getY()
{
	return this->yLoc_;
}

Shoot ** Player::getShoots()
{
    return &this->_shoots[0];
}