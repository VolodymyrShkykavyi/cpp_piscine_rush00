#include "EnemyAsteroid.hpp"

EnemyAsteroid::EnemyAsteroid(){}

EnemyAsteroid::EnemyAsteroid(EnemyAsteroid const &src){
    *this = src;
}

EnemyAsteroid & EnemyAsteroid::operator=(EnemyAsteroid const &other){
    if (this != &other)
    {
        this->_size = other.getSize();
        this->_xLoc = other.getX();
        this->_yLoc = other.getY();
        this->_icon = other.getIcon();
        this->_win = other.getWin();
        this->_alive = other.getAlive();
        this->_pointCost = other.getPointCost();
        this->_iconsArr[0] = other._iconsArr[0];
        this->_iconsArr[1] = other._iconsArr[1];
        this->_iconsArr[2] = other._iconsArr[2];
    }
    return *this;
}

EnemyAsteroid::EnemyAsteroid(WINDOW *win)
{
    this->_win = win;
    this->_size = 1;
    this->_speed = 0.1;
    this->_iconsArr[0] = (char*)"🌖";
    this->_iconsArr[1] = (char*)"🌑";
    this->_iconsArr[2] = (char*)"☄";
    this->_icon = this->_iconsArr[rand() % 3];
    this->_alive = false;
    this->setStartPos();
}

void EnemyAsteroid::setStartPos()
{
    int maxX = 0;
    int maxY = 0;

    getmaxyx(this->_win, maxY, maxX);
    maxY -= 1;
    this->_xLoc = maxX - 1;
    this->_yLoc = rand() % (maxY - 2) + 1;
    this->_yLoc += 1;
}
