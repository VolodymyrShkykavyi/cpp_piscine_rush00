/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2050/06/23 13:46:50 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/24 16:20:20 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"


Game::Game() {}

Game::Game(Game const &src) {
    *this = src;
}

Game::~Game() {}

void Game::init() {
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    clear();
    noecho();
    cbreak();
    curs_set(0);
    this->points = 0;
    this->time = 0;
    keypad(stdscr, true);
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    getmaxyx(stdscr, this->yMax, this->xMax);
    if (this->yMax < 10) {
        std::cout << "Window too small, make it bigger!";
        endwin();
        exit(0);
    }
    this->playwin = newwin(0, 0, 0, 0);
    nodelay(playwin, true);
    player = new Player(playwin, 1, 1, '>');
    this->playerShoots = player->getShoots();
    for (int i = 0; i < 50; i++) {
        this->enemyShoots[i] = new Shoot(this->playwin, 0, 0, -1);
    }
    for (int i = 0; i < 50; i++){
        this->enemyShip[i] = new EnemyShip(this->playwin, &this->enemyShoots[0]);
        // this->enemyShip[i]->setAlive(true);
    }
    for (int i = 0; i < 50; i++) {
        enemyAsteroid[i] = new EnemyAsteroid(this->playwin);
    }
    done = false;
    this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
}

void Game::add_ass() {
    for (int i = 0; i < 50; i++) {
        if (this->time % 100 == 0) {
            if (enemyAsteroid[i]->getAlive() == false) {
                enemyAsteroid[i]->setStartPos();
                enemyAsteroid[i]->setAlive(true);
                break ;
            }
        }
    }
    for (int i = 0; i < 50; i++)
    {
        if (this->time % 200 == 0){    
            if (enemyShip[i]->getAlive() == false) {
                enemyShip[i]->setStartPos();
                enemyShip[i]->setAlive(true);
                break;
        }
    }
    }
}

void Game::check_col() {
	static int immortal_time = 0;
    int type = 0;

	if (immortal_time > 0)
		immortal_time--;
	if (immortal_time == 0  && player->getImmortal() == true){
     		player->setImmortal(false);
    }
    for (int j = 0; j < 50; j++) {
        if (enemyAsteroid[j]->getAlive()) {
            for (int i = 0; i < 100; i++) {
                if (playerShoots[i]->getAlive()) {
                    if (playerShoots[i]->getX() >= enemyAsteroid[j]->getX() - 1 &&
                        playerShoots[i]->getX() <= enemyAsteroid[j]->getX() + enemyAsteroid[j]->getSpeed() + 1 &&
                        playerShoots[i]->getY() == enemyAsteroid[j]->getY()) {
                        playerShoots[i]->setAlive(false);
                    	this->points++;
                        enemyAsteroid[j]->setAlive(false);
                    }
                        if (playerShoots[i]->getX() >= enemyShip[j]->getX() - 1 &&
                        playerShoots[i]->getX() <= enemyShip[j]->getX() + enemyShip[j]->getSpeed() + 1 &&
                        playerShoots[i]->getY() == enemyShip[j]->getY()) {
                        playerShoots[i]->setAlive(false);
                        this->points += 3;
                        enemyShip[j]->setAlive(false);
                    }
                }
            }
            if (player->getImmortal() == false
                && (
                    (player->getX() == enemyAsteroid[j]->getX() && player->getY() == enemyAsteroid[j]->getY() && (type = 1))
                    || (player->getX() == enemyShoots[j]->getX() && player->getY() == enemyShoots[j]->getY() && (type = 2))
                    || (player->getX() == enemyShip[j]->getX() && player->getY() == enemyShip[j]->getY() && (type = 3)))
                ) {
                if (type == 1){
                    enemyAsteroid[j]->setAlive(false);
                } else if (type == 2){
                    enemyShoots[j]->setAlive(false);
                } else if (type == 3){
                    enemyShip[j]->setAlive(false);
                }
                player->removeLive();
                immortal_time = 180;
                player->setImmortal(true);
                if (player->getLives() < 1){
                	done = true;
                	while (1) {
                	    wclear(playwin);
                	    attron(COLOR_PAIR(1));
                	    mvprintw(this->yMax / 2, this->xMax /2 - 1, "*GAME OVER*");
                	    attroff(COLOR_PAIR(1));
                	    refresh();
                	}
            }
            }
        }
    }
}

void Game::moveall() {
    for (int i = 0; i < 100; i++) {
        if (i < 50)
        {
            if (enemyShip[i]->getAlive() == true) {
                enemyShip[i]->move();
                enemyShip[i]->display();
                if (this->time % 100 == 0)
                    enemyShip[i]->shoot();
            }
            if (enemyShip[i]->getX() < 1)
                enemyShip[i]->setStartPos();
        }
        if (i < 50) {
            if (enemyAsteroid[i]->getAlive() == true) {
                enemyAsteroid[i]->move();
                enemyAsteroid[i]->display();
            }
            if (enemyAsteroid[i]->getX() < 1)
                enemyAsteroid[i]->setStartPos();
            this->enemyShoots[i]->move();
            this->enemyShoots[i]->display();
        }
        this->playerShoots[i]->move();
        this->playerShoots[i]->display();
    }
}

void Game::start() {
    init();
    while (!done) {
    	// attron(COLOR_PAIR(1));
        getmaxyx(playwin, this->yMax, this->xMax);
        this->t1 = clock() / (CLOCKS_PER_SEC / FPS);
        if (this->t1 > this->t2) {
            this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
            this->time++;
            player->getmv(yMax, xMax);
            wclear(playwin);
            player->display();
            // box(playwin, 0, 0);
            add_ass();
            moveall();
            check_col();
            refresh();
            mvwprintw(playwin, 1, 1, "lives: %d", player->getLives());
            mvwprintw(playwin, 1, 10, "TIME: %d POINTS: %d", this->time / FPS, this->points);
            // attroff(COLOR_PAIR(1));
        }
    }
    endwin();
}
