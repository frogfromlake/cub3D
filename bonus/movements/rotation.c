/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:28:21 by gohar             #+#    #+#             */
/*   Updated: 2022/07/04 17:56:01 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	rotdir_next(t_data *game)
{
	if (game->player.dir.y < -0.95 && game->player.dir.x > -1)
		game->player.p_dir = SOUTH;
	else if (game->player.dir.y > -0.95 && game->player.dir.y < 0
		&& game->player.dir.x > 0 && game->player.dir.x < 0.95)
		game->player.p_dir = SE;
	else if (game->player.dir.x < -0.95 && game->player.dir.x > -1)
		game->player.p_dir = WEST;
	else if (game->player.dir.y > -0.95 && game->player.dir.y < 0
		&& game->player.dir.x < 0 && game->player.dir.x > -0.95)
		game->player.p_dir = SW;
}

void	rotdir(t_data *game, int p)
{
	float	old_dir_x;
	float	rot_speed;

	rot_speed = game->mouse.rotation_speed * p;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot_speed)
		- game->player.dir.y * sin(rot_speed);
	game->player.dir.y = old_dir_x * sin(rot_speed)
		+ game->player.dir.y * cos(rot_speed);
	if (game->player.dir.y > 0.95 && game->player.dir.x < 1)
		game->player.p_dir = NORTH;
	else if (game->player.dir.y < 0.95 && game->player.dir.y > 0
		&& game->player.dir.x < 0 && game->player.dir.x > -0.95)
		game->player.p_dir = NW;
	else if (game->player.dir.x > 0.95 && game->player.dir.x < 1)
		game->player.p_dir = EAST;
	else if (game->player.dir.y < 0.95 && game->player.dir.y > 0
		&& game->player.dir.x > 0 && game->player.dir.x < 0.95)
		game->player.p_dir = NE;
	rotdir_next(game);
}
