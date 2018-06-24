/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:19:13 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/24 13:26:04 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Player.hpp"
#include <locale.h>

int	main(){
	Game g;
	setlocale(LC_ALL, "");
	g.start();
	return 0;
}
