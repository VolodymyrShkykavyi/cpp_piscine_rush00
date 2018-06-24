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
	Enemy(Enemy const &src);
	Enemy & operator=(Enemy const &other);
	~Enemy();
    void    display();
	int	    getSize() const;
	int	    getSpeed() const;
	int	    getX() const;
	int     getY() const;
	bool	getAlive() const;
	char * 	getIcon() const;
	WINDOW* getWin() const;
	int 	getPointCost() const;
	void	setAlive(bool is);
    void    setStartPos();
    void	move();
};

#endif