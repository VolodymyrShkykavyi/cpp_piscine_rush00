#include "Shoot.hpp"

Shoot::Shoot(WINDOW *win, int y, int x, int direction)
{
    this->_win = win;
    this->_speed = 2;
    this->_direction = direction;
    this->_xLoc = x + direction;
    this->_yLoc = y + direction;
}

void Shoot::move()
{
    this->_xLoc += this->_direction * this->_speed;
}

void    Shoot::display()
{
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