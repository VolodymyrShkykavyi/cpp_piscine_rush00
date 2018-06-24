#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::Enemy(WINDOW *newwin) {
	this->_icon = (char*)"⋆";
	this->_speed = 0.2;
	this->_alive = false;
	this->_win = newwin;
	this->setStartPos();
}

Enemy::~Enemy() {}

int		Enemy::getSize()
{
	return this->_size;
}

int		Enemy::getSpeed()
{
	return this->_speed;
}

int		Enemy::getX()
{
	return this->_xLoc;
}

int		Enemy::getY()
{
	return this->_yLoc;
}

void    Enemy::display()
{
	wattron(this->_win, COLOR_PAIR(4));
    mvwaddstr(this->_win, this->_yLoc, this->_xLoc, this->_icon);
    wattroff(this->_win, COLOR_PAIR(4));
}

void	Enemy::move()
{
	this->_xLoc -= this->_speed;
}

bool	Enemy::getAlive()
{
	return this->_alive;
}

void	Enemy::setAlive(bool is)
{
	this->_alive = is;
}

void Enemy::setStartPos(){
	int maxX = 0;
    int maxY = 0;

    getmaxyx(this->_win, maxY, maxX);
    maxY -= 1;
    this->_xLoc = maxX - 1;
    this->_yLoc = rand() % (maxY - 2) + 1;
    this->_yLoc += 1;
}