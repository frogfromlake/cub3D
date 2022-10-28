/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_left_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:32:13 by fquist            #+#    #+#             */
/*   Updated: 2022/07/04 17:54:21 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// left right
void	moveplayer_per(t_data *game, int p, float move_speed)
{
	game->player.old_x = game->vec.x;
	game->player.old_y = game->vec.y;
	game->player.move_speed = (move_speed + game->player.sprint_speed) * p;
	game->vec.y = game->player.p_y + game->player.dir.x
		* -game->player.move_speed;
	game->vec.x = game->player.p_x - game->player.dir.y
		* game->player.move_speed;
	if (game->map.map[(int)game->vec.y][(int)game->vec.x] != '1'
		&& game->map.map[(int)(game->vec.y + 0.1)][(int)(game->vec.x + 0.1)]
			!= '1'
		&& game->map.map[(int)(game->vec.y - 0.1)][(int)(game->vec.x - 0.1)]
			!= '1')
	{
		game->player.p_x = game->vec.x;
		game->player.p_y = game->vec.y;
	}
}
