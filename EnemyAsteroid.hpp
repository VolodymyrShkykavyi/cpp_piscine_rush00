#ifndef CPP_PISCINE_RUSH00_ENEMYASTEROID_HPP
#define CPP_PISCINE_RUSH00_ENEMYASTEROID_HPP

# include "Enemy.hpp"
# include <cstdlib>
# include <string>

class   EnemyAsteroid: public Enemy
{ 
protected:
	char *_iconsArr[3];
public:

	EnemyAsteroid();
	EnemyAsteroid(EnemyAsteroid const &src);
    EnemyAsteroid(WINDOW *win);
    EnemyAsteroid & operator=(EnemyAsteroid const &other);
    ~EnemyAsteroid();
    void    setStartPos();
};

#endif
