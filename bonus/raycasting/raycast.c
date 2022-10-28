/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:27 by gohar             #+#    #+#             */
/*   Updated: 2022/07/08 00:12:29 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

//game->wall_heights[i] = (int)(h / perp_wall_dist); 
//	-> Calculate height of line to draw on screen
int	calculating_walls(t_data *game)
{
	int		i;

	game->h = game->fov_factor_y * HEIGHT;
	i = -1;
	while (++i < WIDTH)
	{
		game->perp_wall_dist_s[i] = find_hit(game, i);
		game->wall_heights[i]
			= ((int)(game->h / game->perp_wall_dist_s[i])) + HEIGHT * 0.02;
	}
	return (0);
}
