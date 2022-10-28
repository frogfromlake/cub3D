/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:40:27 by fquist            #+#    #+#             */
/*   Updated: 2022/07/05 23:23:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_vec	calc_dir(int d)
{
	if (d == NORTH)
		return ((t_vec){0.0, 1.0});
	else if (d == SOUTH)
		return ((t_vec){0.0, -1.0});
	else if (d == EAST)
		return ((t_vec){1.0, 0.0});
	else if (d == WEST)
		return ((t_vec){-1.0, 0.0});
	else
		return ((t_vec){0.0, 0.0});
}

void	init_variables(t_data *game)
{
	if ((WIDTH == 1920 || WIDTH == 1600)
		&& (HEIGHT == 1080 || HEIGHT == 900))
	{
		game->screen_width = WIDTH;
		game->screen_height = HEIGHT;
	}
	else
		error(game, "\033[0;31mError: Unsupported resolution."
			" See Headerfile for more Infos.\e[0m\n");
	game->fov_factor_x = 0.66;
	game->fov_factor_y = 0.5;
	game->player.dir = calc_dir(game->player.p_dir);
	game->wall_heights = malloc(game->screen_width * sizeof(int));
	if (!game->wall_heights)
		error(game, "\033[0;31mError: Allocation for"
			" 'wall_heights' failed.\e[0m\n");
	game->wall_types = malloc(game->screen_width * sizeof(char));
	if (!game->wall_types)
		error(game, "\033[0;31mError: Allocation for 'wall_types' failed.\e[0m\n");
	game->wall_shade = malloc(game->screen_width * sizeof(float));
	if (!game->wall_shade)
		error(game, "\033[0;31mError: Allocation for 'wall_shade' failed.\e[0m\n");
}
