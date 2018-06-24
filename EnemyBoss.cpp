#include "EnemyBoss.hpp"

EnemyBoss::EnemyBoss() {}

EnemyBoss::EnemyBoss(EnemyBoss const &src){
	*this = src;
}

EnemyBoss::EnemyBoss(WINDOW *win, Shoot **shoots) {
	this->_win = win;
	this->_shoots = shoots;
	this->_size = 1;
	this->_speed = 0.1;
	this->_alive = false;
	this->_direction = 1;
	this->_hp = 0;
	this->_maxHp = 0;
	this->setStartPos();
}

EnemyBoss & EnemyBoss::operator=(EnemyBoss const &other){
	if (this != &other){
		this->_size = other.getSize();
        this->_xLoc = other.getX();
        this->_yLoc = other.getY();
        this->_icon = other.getIcon();
        this->_win = other.getWin();
        this->_alive = other.getAlive();
        this->_pointCost = other.getPointCost();
        this->_shoots = other._shoots;
        this->_direction = other._direction;
        this->_hp = other._hp;
        this->_maxHp = other._maxHp;
	}
	return *this;
}

void EnemyBoss::setStartPos() {
	int maxX = 0;
	int maxY = 0;

	getmaxyx(this->_win, maxY, maxX);
	maxY -= 2;

	this->_xLoc = maxX - 2;
	this->_yLoc = rand() % (maxY - 4) + 3;
	this->_yLoc += 1;
}

void EnemyBoss::shoot() {
	int num = 0;

	if (this->getAlive() == true) {
		for (int i = 0; i < 50; i++) {
			if (this->_shoots[i]->getAlive() == false) {
				this->_shoots[i]->setAlive(true);
				this->_shoots[i]->setX(this->_xLoc);
				if (num == 0) {
					this->_shoots[i]->setY(this->_yLoc - 2);
				} else if (num == 1) {
					this->_shoots[i]->setY(this->_yLoc);
				} else if (num == 2) {
					this->_shoots[i]->setY(this->_yLoc + 2);
				}
				num++;
			}
			if (num == 3){
				break;
			}
		}
	}
}

void EnemyBoss::display() {
	if (this->getAlive()) {

		mvwaddstr(this->_win, this->_yLoc - 2, this->_xLoc, "<");
		mvwaddstr(this->_win, this->_yLoc - 1, this->_xLoc, "◢");
		mvwaddstr(this->_win, this->_yLoc - 1, this->_xLoc + 1, "◼");
		mvwaddstr(this->_win, this->_yLoc, this->_xLoc - 1, "👽");
		mvwaddstr(this->_win, this->_yLoc, this->_xLoc + 1, "🕸");
		mvwaddstr(this->_win, this->_yLoc + 1, this->_xLoc + 1, "◼");
		mvwaddstr(this->_win, this->_yLoc + 1, this->_xLoc, "◥");
		mvwaddstr(this->_win, this->_yLoc + 2, this->_xLoc, "<");
	}
}

void EnemyBoss::move() {
	if (this->getAlive()) {
		int maxX = 0;
		int maxY = 0;

		getmaxyx(this->_win, maxY, maxX);

		this->_yLoc += this->_direction * this->_speed;
		if (this->_yLoc <= 4) {
			this->_direction = 1;
		} else if (this->_yLoc >= maxY - 3) {
			this->_direction = -1;
		}
	}
}

void	EnemyBoss::removeLife() {
	if (this->_hp > 0) {
		this->_hp--;
	} else {
		this->setAlive(false);
	}
}

bool EnemyBoss::checkShootCollision(Shoot *playerShoot) {
	if (this->getAlive()) {
			int x = playerShoot->getX();
			int y = playerShoot->getY();

			if (x >= this->getX() - 2 &&
				y >= this->_yLoc - 2 &&
				y <= this->_yLoc + 2
					) {
				playerShoot->setAlive(false);
				return true;
		}
	}
	return false;
}

bool EnemyBoss::checkPlayerCollision(int y, int x) {
	if (this->getAlive()) {
		if (x >= this->_xLoc - 1 &&
			y >= this->_yLoc - 2 &&
			y <= this->_yLoc + 2
				) {
			return true;
		}
	}
	return false;
}

void	EnemyBoss::setHp(int hp) {
	this->_maxHp += hp;
	this->_hp = this->_maxHp;
}