/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:58 by gohar             #+#    #+#             */
/*   Updated: 2022/07/06 20:46:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	dda_hits(t_data *game, int *hit)
{
	if (game->map.map[game->m_y - game->map_values.y - 1]
		[game->map_values.x] == '1'
		|| game->map.map[game->m_y - game->map_values.y - 1]
		[game->map_values.x] == 'P')
		(*hit) = 1;
	else if (game->map.map[game->m_y - game->map_values.y - 1]
		[game->map_values.x] == 'F')
		game->enemy->ray_hit = true;
}

/*
	game->map_values.x: which box of the map we're in
	if (sideDist->x < sideDist->y):
	jump to next map square, either in x-direction, or in y-direction
	if (game->map.map[game->m_y - game->map_values.y - 1][game->map_values.x]
	== '1'):
	Check if ray has hit a wall
*/
int	dda(t_data *game, t_vec *sideDist, t_vec deltaDist, t_intpair step)
{
	int			hit;
	int			side;

	hit = 0;
	while (hit == 0)
	{
		if (sideDist->x < sideDist->y)
		{
			sideDist->x += deltaDist.x;
			game->map_values.x += step.x;
			side = 0;
		}
		else
		{
			sideDist->y += deltaDist.y;
			game->map_values.y += step.y;
			side = 1;
		}
		dda_hits(game, &hit);
	}
	return (side);
}
