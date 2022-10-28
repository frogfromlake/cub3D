/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:44 by gohar             #+#    #+#             */
/*   Updated: 2022/07/04 17:56:01 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

// if (ray.x < 0): what direction to step in x or y-direction (either +1 or -1).
static t_intpair	calc_step(t_vec ray)
{
	t_intpair	step;

	if (ray.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

// map.x: which box of the map we're in.
static t_vec	calc_side_dist(t_data *game, t_vec ray, t_vec delta_dist)
{
	t_vec		side_dist;
	t_intpair	map;

	map.x = (int)(game->player.p_x);
	map.y = (int)(game->m_y - game->player.p_y);
	if (ray.x < 0)
		side_dist.x = (game->player.p_x - map.x) * delta_dist.x;
	else
		side_dist.x = (1.0 - game->player.p_x + map.x) * delta_dist.x;
	if (ray.y < 0)
		side_dist.y = ((game->m_y - game->player.p_y) - map.y) * delta_dist.y;
	else
		side_dist.y = (1.0 - (game->m_y - game->player.p_y) + map.y)
			* delta_dist.y;
	return (side_dist);
}

static float	calc_wallshade(t_data *g, t_vec sdist, t_vec ray, t_vec ddist)
{
	float	res;

	if (g->side == 0)
	{
		res = (sdist.x - ddist.x) / ddist.y;
		if (ray.y > 0)
			res = g->player.p_y - res;
		else
			res = g->player.p_y + res;
	}
	else
	{
		res = (sdist.y - ddist.y) / ddist.x;
		if (ray.x > 0)
			res = g->player.p_x + res;
		else
			res = g->player.p_x - res;
	}
	res -= (int)res;
	return (res);
}

static void	set_wall_type(t_data *game, t_intpair step, int i)
{
	game->map_values.y = (int)(game->m_y) - (game->map_values.y) - 1;
	if (game->map.map[game->map_values.y][game->map_values.x] == 'P')
		game->wall_types[i] = 'P';
	else if (game->side == 0)
	{
		if (step.x == 1)
			game->wall_types[i] = 'S';
		else
			game->wall_types[i] = 'W';
	}
	else
	{
		if (step.y == 1)
			game->wall_types[i] = 'N';
		else
			game->wall_types[i] = 'E';
	}
}

// delta_dist.x: Length the ray must travel to cover one box in x,y direction.
float	find_hit(t_data *game, int i)
{
	t_vec		ray;
	t_vec		delta_dist;
	t_vec		side_dist;
	t_intpair	step;

	ray = calc_ray(game, i);
	delta_dist.x = fabs(1 / ray.x);
	delta_dist.y = fabs(1 / ray.y);
	step = calc_step(ray);
	side_dist = calc_side_dist(game, ray, delta_dist);
	game->map_values.x = (int)(game->player.p_x);
	game->map_values.y = (int)(game->m_y - game->player.p_y);
	game->side = dda(game, &side_dist, delta_dist, step);
	set_wall_type(game, step, i);
	game->wall_shade[i] = calc_wallshade
		(game, side_dist, ray, delta_dist);
	if (game->side == 0)
		return (side_dist.x - delta_dist.x);
	else
		return (side_dist.y - delta_dist.y);
}
