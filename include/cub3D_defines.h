/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:08:56 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 19:09:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

/* ************************************************************************** */
/* 	DEFINES																	  */
/* ************************************************************************** */
# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[1;32m"
# define LGREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"
# define RESET	"\e[0m"

// Player Speed
# define PLAYER_SPEED 0.055
# define PLAYER_SPRINT_SPEED 0.05

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define NE 0.5
# define SE 1.5
# define SW 2.5
# define NW 3.5
# define UP -0.4
# define DOWN 0.4
# define LEFT -0.4
# define RIGHT 0.4
# define TIMER 100

#endif