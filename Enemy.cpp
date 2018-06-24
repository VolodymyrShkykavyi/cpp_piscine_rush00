#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::Enemy(Enemy const &src) {
	*this = src;
}

Enemy::Enemy(WINDOW *newwin) {
	this->_icon = (char*)"⋆";
	this->_speed = 0.2;
	this->_alive = false;
	this->_win = newwin;
	this->setStartPos();
}

Enemy & Enemy::operator=(Enemy const &other){
	if (this != &other){
		this->_size = other.getSize();
		this->_xLoc = other.getX();
		this->_yLoc = other.getY();
		this->_icon = other.getIcon();
		this->_win = other.getWin();
		this->_alive = other.getAlive();
		this->_pointCost = other.getPointCost();
	}
	return *this;
}

Enemy::~Enemy() {}

int		Enemy::getSize() const{
	return this->_size;
}

int		Enemy::getSpeed()const
{
	return this->_speed;
}

int		Enemy::getX()const
{
	return this->_xLoc;
}

int		Enemy::getY()const
{
	return this->_yLoc;
}

char * Enemy::getIcon()const{
	return this->_icon;
}

WINDOW* Enemy::getWin()const{
	return this->_win;
}

int 	Enemy::getPointCost()const{
	return this->_pointCost;
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

bool	Enemy::getAlive()const
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