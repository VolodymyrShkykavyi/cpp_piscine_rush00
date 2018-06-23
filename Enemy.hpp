#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <ncurses.h>

class Enemy
{
protected:
	int	_size;
	float	_xLoc, _yLoc;
	float	_speed;
    char _icon;
    WINDOW * _win;

public:
	Enemy();
	~Enemy();

    void    display();
	int	    getSize();
	int	    getSpeed();
	int	    getX();
	int     getY();
    void    setStartPos();
    void	move();
};

#endif