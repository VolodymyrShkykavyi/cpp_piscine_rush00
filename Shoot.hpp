#ifndef CPP_PISCINE_RUSH00_SHOOT_HPP
#define CPP_PISCINE_RUSH00_SHOOT_HPP

# include <ncurses.h>

class Shoot
{
private:
    int _direction;
    float _speed;
    float   _xLoc, _yLoc;
    int     _maxX, _maxY;
    WINDOW  * _win;
    bool    _alive;

public:
    Shoot();
    Shoot(Shoot const &src);
    Shoot(WINDOW *win, int y, int x, int direction = -1);
    Shoot & operator=(Shoot const &other);
    ~Shoot();
    void    move();
    void    display();
    int	    getX();
    int     getY();
    void	setX(int pos);
    void    setY(int pos);
    bool    getAlive();
    void    setAlive(bool value);
};

#endif
