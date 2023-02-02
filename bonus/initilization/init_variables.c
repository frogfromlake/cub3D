/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:40:27 by fquist            #+#    #+#             */
/*   Updated: 2023/02/02 03:38:25 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

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

static void	allocate_game_vars(t_data *game)
{
	game->wall_heights = malloc(WIDTH * sizeof(int));
	if (!game->wall_heights)
		error(game, "\033[0;31mError:"
			" Allocation for 'wall_heights' failed.\e[0m\n");
	game->wall_types = malloc(WIDTH * sizeof(char));
	if (!game->wall_types)
		error(game, "\033[0;31mError: Allocation for 'wall_types' failed.\e[0m\n");
	game->wall_shade = malloc(WIDTH * sizeof(float));
	if (!game->wall_shade)
		error(game, "\033[0;31mError: Allocation for 'wall_shade' failed.\e[0m\n");
}

void	init_game_variables(t_data *game)
{
	if ((WIDTH != 1920 && WIDTH != 1600)
		|| (HEIGHT != 1080 && HEIGHT != 900))
	{
		error(game, "\033[0;31mError: Unsupported resolution."
			" See Headerfile for more Infos.\e[0m\n");
		exit(EXIT_FAILURE);
	}
	game->runtime = 0;
	game->mouse.rotation_speed = MOUSE_SENSITIVITY;
	game->mouse.init_mousepos = false;
	game->fov_factor_x = 0.66;
	game->fov_factor_y = 0.5;
	game->player.dir = calc_dir(game->player.p_dir);
	game->player.firing = false;
	game->player.f_aim = false;
	game->player.running = false;
	game->player.sprinting = false;
	game->player.ammo = 20;
	allocate_game_vars(game);
}

void	init_enemy_variables(t_data *game)
{
	game->enemy->hit = false;
	game->enemy->first = true;
	game->enemy->dead = false;
	game->enemy->enemy_frame = 0;
	game->enemy->hit = 0;
	game->minimap.map_size = 15;
	game->minimap.map_zoom = 6;
	(game->imgs.enemy) = ft_calloc(75, 21 * sizeof(mlx_texture_t));
	if (!(game->imgs.enemy))
		error(game, "\033[0;31mError: Allocation for 'imgs.enemy' failed.\e[0m\n");
	(game->imgs.sprites) = ft_calloc(75, 10 * sizeof(mlx_texture_t));
	if (!(game->imgs.sprites))
		error(game, "\033[0;31mError:"
			" Allocation for 'imgs.sprites' failed.\e[0m\n");
	game->time_count = game->m_x * game->m_y * TIMER;
}
