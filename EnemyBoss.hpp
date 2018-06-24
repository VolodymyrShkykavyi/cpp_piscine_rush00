
#ifndef ENEMYBOSS_HPP
#define ENEMYBOSS_HPP

#include "Enemy.hpp"
#include <ncurses.h>
#include "Shoot.hpp"

class EnemyBoss : public Enemy
{
	Shoot **	_shoots;
	int 		_direction;
	int 		_hp;
	int 		_maxHp;

public:
	EnemyBoss();
	EnemyBoss(WINDOW *win, Shoot **shoot);
	~EnemyBoss();

	void shoot();
	void setStartPos();
	void display();
	void move();
	void setHp(int hp);

	bool checkShootCollision(Shoot *playerShoots);
	bool checkPlayerCollision(int y, int x);
	void removeLife();
//	void	setAlive(bool is);
};

#endif
