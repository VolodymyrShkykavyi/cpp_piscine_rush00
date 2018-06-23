#ifndef CPP_PISCINE_RUSH00_SHOOT_HPP
#define CPP_PISCINE_RUSH00_SHOOT_HPP

# include <ncurses.h>

class Shoot
{
private:
    int _direction;
    int _speed;
    float   _xLoc, _yLoc;
    WINDOW  * _win;

public:
    Shoot(WINDOW *win, int y, int x, int direction = -1);
    void    move();
    void    display();
    int	    getX();
    int     getY();
};

#endif
