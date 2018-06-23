#include "Enemy.hpp"

Enemy::Enemy() {}

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
    mvwaddch(this->_win, this->_yLoc, this->_xLoc, this->_icon);
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