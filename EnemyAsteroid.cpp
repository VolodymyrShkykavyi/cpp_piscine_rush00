#include "EnemyAsteroid.hpp"

EnemyAsteroid::EnemyAsteroid(WINDOW *win)
{
    this->_win = win;
    this->_size = 1;
    this->_speed = 0.1;
    this->_icon = '*';
    this->_alive = false;
    this->setStartPos();
}

void EnemyAsteroid::setStartPos()
{
    int maxX = 0;
    int maxY = 0;

    getmaxyx(this->_win, maxY, maxX);
    this->_xLoc = maxX - 1;
    this->_yLoc = rand() % (maxY - 2) + 1;
}