#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <ncurses.h>
# include <string>

class Enemy
{
protected:
	int	_size;
	float	_xLoc, _yLoc;
	float	_speed;
    char    *_icon;
    WINDOW * _win;
    bool 	_alive;
    int		_pointCost;
public:
	Enemy();
	Enemy(WINDOW *newwin);
	~Enemy();
    void    display();
	int	    getSize();
	int	    getSpeed();
	int	    getX();
	int     getY();
	bool	getAlive();
	void	setAlive(bool is);
    void    setStartPos();
    void	move();
};

#endif