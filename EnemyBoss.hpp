
#ifndef ENEMYBOSS_HPP
#define ENEMYBOSS_HPP

#include "Enemy.hpp"
#include <ncurses.h>
#include "Shoot.hpp"

class EnemyBoss : public Enemy
{
	Shoot **	_shoots;
	int 		_direction;

public:
	EnemyBoss();
	EnemyBoss(WINDOW *win, Shoot **shoot);
	~EnemyBoss();

	void shoot();
	void setStartPos();
	void display();
	void move();
};

#endif
