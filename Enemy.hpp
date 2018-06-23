#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy
{
protected:
	int	_size;
	int	_xLoc, _yLoc;
	int	_speed;

public:
	Enemy();
	~Enemy();
	
	int	getSize();
	int	getSpeed();
	int	getX();
	int getY();
};

#endif