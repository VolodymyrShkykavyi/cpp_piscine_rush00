#ifndef CPP_PISCINE_RUSH00_ENEMYASTEROID_HPP
#define CPP_PISCINE_RUSH00_ENEMYASTEROID_HPP

# include "Enemy.hpp"
# include <cstdlib>

class   EnemyAsteroid: public Enemy
{   
public:
    EnemyAsteroid(WINDOW *win);
    //EnemyAsteroid(WINDOW *win, int size);
    ~EnemyAsteroid();
    void    setStartPos();
};

#endif
