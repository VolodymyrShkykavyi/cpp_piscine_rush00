#include "Shoot.hpp"

Shoot::Shoot(WINDOW *win, int y, int x, int direction)
{
    this->_win = win;
    this->_speed = 1.5;
    this->_direction = direction;
    this->_xLoc = x + direction;
    this->_yLoc = y + direction;
    this->_alive = false;

    getmaxyx(this->_win, this->_maxY, this->_maxX);
}

void Shoot::move()
{
    if (this->_alive) {
        this->_xLoc += this->_direction * this->_speed;
        if (this->_xLoc >= this->_maxX){
            this->setAlive(false);
        }
    }
}

void    Shoot::display()
{
    if (this->_alive)
        mvwaddch(this->_win, this->_yLoc, this->_xLoc, '-');
}

int		Shoot::getX()
{
    return this->_xLoc;
}

int		Shoot::getY()
{
    return this->_yLoc;
}

bool    Shoot::getAlive()
{
    return this->_alive;
}

bool    Shoot::setAlive(bool value)
{
    this->_alive = value;
}

void    Shoot::setX(int pos)
{
    this->_xLoc = pos;
}

void    Shoot::setY(int pos)
{
    this->_yLoc = pos;
}