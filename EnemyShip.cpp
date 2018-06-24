#include "EnemyShip.hpp"
#include <iostream>

EnemyShip::EnemyShip(){}

EnemyShip::EnemyShip(EnemyShip const &src){
	*this = src;
}

EnemyShip & EnemyShip::operator=(EnemyShip const &other){
    if (this != &other){
        this->_size = other.getSize();
        this->_xLoc = other.getX();
        this->_yLoc = other.getY();
        this->_icon = other.getIcon();
        this->_win = other.getWin();
        this->_alive = other.getAlive();
        this->_pointCost = other.getPointCost();
        this->_shoots = other._shoots;
    }
    return *this;
}

EnemyShip::EnemyShip(WINDOW *win, Shoot **shoot){
	this->_win = win;
    this->_size = 1;
    this->_speed = 0.1;
    this->_icon = (char *)"🐉";
    this->_alive = false;
    this->setStartPos();
    this->_shoots = shoot;
}

void EnemyShip::setStartPos()
{
    int maxX = 0;
    int maxY = 0;

    getmaxyx(this->_win, maxY, maxX);
    maxY -= 1;
    this->_xLoc = maxX - 1;
    this->_yLoc = rand() % (maxY - 2) + 1;
    this->_yLoc += 1;
}

void EnemyShip::shoot(){
	if (this->getAlive() == true)
	{
		for (int i = 0; i < 50; i++)
		{
			if (this->_shoots[i]->getAlive() == false) {
            	this->_shoots[i]->setAlive(true);
            	this->_shoots[i]->setX(this->_xLoc);
            	this->_shoots[i]->setY(this->_yLoc);
            	break;
        	}
		}
	}
}