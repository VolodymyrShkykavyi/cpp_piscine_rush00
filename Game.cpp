/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2050/06/23 13:46:15 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 18:20:50 by bpodlesn         ###   ########.fr       */
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
    noecho();
    cbreak();
    curs_set(0);
    getmaxyx(stdscr, this->yMax, this->xMax);
    if (this->yMax < 10) {
        std::cout << "Window too small, make it bigger!";
        endwin();
        exit(0);
    }
    this->playwin = newwin(0, 0, 0, 0);
    keypad(playwin, true);
    nodelay(playwin, true);
    player = new Player(playwin, 1, 1, '>');
    this->playerShoots = player->getShoots();
    for (int i = 0; i < 50; i++) {
        enemyAsteroid[i] = new EnemyAsteroid(this->playwin);
    }
    done = false;
    this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
}

void Game::add_ass() {
    for (int i = 0; i < 50; i++) {
        if (clock() % 200 == 0) {
            if (enemyAsteroid[i]->getAlive() == false) {
                enemyAsteroid[i]->setStartPos();
                enemyAsteroid[i]->setAlive(true);
            }
        }
    }
}

void Game::check_col() {

    for (int j = 0; j < 50; j++) {
        if (enemyAsteroid[j]->getAlive()) {
            for (int i = 0; i < 100; i++) {
                if (playerShoots[i]->getAlive()) {
                    if (playerShoots[i]->getX() >= enemyAsteroid[j]->getX() &&
                        playerShoots[i]->getX() <= enemyAsteroid[j]->getX() + enemyAsteroid[j]->getSpeed() + 1 &&
                        playerShoots[i]->getY() == enemyAsteroid[j]->getY()) {
                        playerShoots[i]->setAlive(false);
                        enemyAsteroid[j]->setAlive(false);
                    }
                }
            }
            if ((player->getX() == enemyAsteroid[j]->getX()) && (player->getY() == enemyAsteroid[j]->getY())) {
                done = true;
                while (1) {
                    wclear(playwin);
                    box(playwin, 0, 0);
                    mvwprintw(playwin, 1, 1, "you lose");
                    wrefresh(playwin);
                }
            }
        }
    }


}

void Game::moveall() {
    for (int i = 0; i < 100; i++) {
        if (i < 50) {
            if (enemyAsteroid[i]->getAlive() == true) {
                enemyAsteroid[i]->move();
                enemyAsteroid[i]->display();
            }
            if (enemyAsteroid[i]->getX() < 1)
                enemyAsteroid[i]->setStartPos();
        }
        this->playerShoots[i]->move();
        this->playerShoots[i]->display();
    }
}

void Game::start() {
    init();
    while (!done) {
        getmaxyx(playwin, this->yMax, this->xMax);
        this->t1 = clock() / (CLOCKS_PER_SEC / FPS);
        if (this->t1 > this->t2) {
            this->t2 = clock() / (CLOCKS_PER_SEC / FPS);
            player->getmv(yMax, xMax);
            wclear(playwin);
            player->display();
            box(playwin, 0, 0);
            add_ass();
            moveall();
            check_col();
            refresh();
        }
    }
    endwin();
}
