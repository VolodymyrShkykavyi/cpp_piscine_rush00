#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP
#include "Shoot.hpp"
#include "Enemy.hpp"
#include <ncurses.h>

class EnemyShip : public  Enemy
{
	Shoot ** _shoots;
public:
	EnemyShip();
	EnemyShip(EnemyShip const &src);
	EnemyShip(WINDOW *win);//, Shoot **shoot);
	~EnemyShip();
	void shoot();
	void setStartPos();
};

#endif