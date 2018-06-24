#include "EnemyBoss.hpp"

/*
 * 	 /0
 * <000
 * 	 \0
 *
 */

EnemyBoss::EnemyBoss() {}

EnemyBoss::EnemyBoss(WINDOW *win, Shoot ** shoots)
{
	this->_win = win;
	this->_shoots = shoots;
	this->_size = 1;
	this->_speed = 0.1;
	this->_alive = false;
	this->_direction = 1;
	this->setStartPos();
}

void EnemyBoss::setStartPos()
{
	int maxX = 0;
	int maxY = 0;

	getmaxyx(this->_win, maxY, maxX);
	maxY -= 2;

	this->_xLoc = maxX - 2;
	this->_yLoc = rand() % (maxY - 3) + 2;
	this->_yLoc += 1;
}

void	EnemyBoss::shoot()
{
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

void	EnemyBoss::display() {
	mvwaddstr(this->_win, this->_yLoc - 1, this->_xLoc, "/");
	mvwaddstr(this->_win, this->_yLoc, this->_xLoc, "<");
	mvwaddstr(this->_win, this->_yLoc, this->_xLoc + 1, "]");
	mvwaddstr(this->_win, this->_yLoc + 1, this->_xLoc, "\\");
}

void	EnemyBoss::move() {
	int maxX = 0;
	int maxY = 0;

	getmaxyx(this->_win, maxY, maxX);

	this->_yLoc += this->_direction * this->_speed;
	if (this->_yLoc <= 3) {
		this->_direction = 1;
	} else if (this->_yLoc >= maxY - 2) {
		this->_direction = -1;
	}
}