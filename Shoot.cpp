#include "Shoot.hpp"

Shoot::Shoot(){}

Shoot::Shoot(Shoot const &src){
    *this = src;
}

Shoot::Shoot(WINDOW *win, int y, int x, int direction)
{
    this->_win = win;
    this->_speed = 1.5;
    if (direction == -1)
        this->_speed = 1;
    this->_direction = direction;
    this->_xLoc = x + direction;
    this->_yLoc = y + direction;
    this->_alive = false;
}

Shoot & Shoot::operator=(Shoot const &other){
    if (this != &other){
        this->_direction = other._direction;
        this->_speed = other._speed;
        this->_yLoc = other._yLoc;
        this->_xLoc = other._xLoc;
        this->_maxX = other._maxX;
        this->_maxY = other._maxY;
        this->_win = other._win;
        this->_alive = other._alive;
    }
    return *this;
}

Shoot::~Shoot(){}

void Shoot::move()
{
    getmaxyx(this->_win, this->_maxY, this->_maxX);   
    if (this->_alive) {
        this->_xLoc += this->_direction * this->_speed;
        if (this->_xLoc >= this->_maxX){
            this->setAlive(false);
        }
        if (this->_direction == -1)
        {
            if (this->_xLoc <= 0){
                this->setAlive(false);
            }
        }
    }
}

void    Shoot::display()
{
    if (this->_alive){
        wattron(this->_win, COLOR_PAIR(1));
        mvwaddstr(this->_win, this->_yLoc, this->_xLoc, "❃");
        wattroff(this->_win, COLOR_PAIR(1));
    }
    if (this->_alive && this->_direction == -1)
    {
        mvwaddstr(this->_win, this->_yLoc, this->_xLoc, "🔥");
    }
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

void    Shoot::setAlive(bool value)
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