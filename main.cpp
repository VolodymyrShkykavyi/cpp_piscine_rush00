/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 21:19:13 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/23 14:30:18 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "Player.hpp"

int	main(){
	Game g;
	g.start();
	return 0;
}
