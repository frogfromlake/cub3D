/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:27 by gohar             #+#    #+#             */
/*   Updated: 2022/06/23 18:26:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

//game->wall_heights[i] = (int)(h / perp_wall_dist); 
//	-> Calculate height of line to draw on screen
int	calculating_walls(t_data *game)
{
	int		i;

	game->h = game->fov_factor_y * game->screen_height;
	i = -1;
	while (++i < game->screen_width)
	{
		game->perp_wall_dist_s[i] = find_hit(game, i);
		game->wall_heights[i] = (int)(game->h / game->perp_wall_dist_s[i]);
	}
	return (0);
}
