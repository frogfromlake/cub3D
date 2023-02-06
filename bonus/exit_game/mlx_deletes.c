/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_deletes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:50:54 by fquist            #+#    #+#             */
/*   Updated: 2023/02/06 22:25:45 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	exit_game_2(t_data *game)
{
	if (game->wall_heights)
		free(game->wall_heights);
	if (game->wall_types)
		free(game->wall_types);
	if (game->wall_shade)
		free(game->wall_shade);
	if (game->map.paths[NORTH])
		free(game->map.paths[NORTH]);
	if (game->map.paths[SOUTH])
		free(game->map.paths[SOUTH]);
	if (game->map.paths[EAST])
		free(game->map.paths[EAST]);
	if (game->map.paths[WEST])
		free(game->map.paths[WEST]);
}

void	exit_game(t_data *game)
{
	int	i;

	i = 0;
	exit_game_2(game);
	if (game->portal)
		free(game->portal);
	if (game->enemy)
		free(game->enemy);
	if (game->map.created == true)
	{
		while (i < game->m_y)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
	}
	if (game->map.map)
		free(game->map.map);
	mlx_stop_sound(game->player.pid[0]);
	mlx_stop_sound(game->player.pid[1]);
	mlx_stop_sound(game->player.pid[2]);
	mlx_stop_sound(game->player.pid[3]);
	mlx_stop_sound(game->player.pid[4]);
	exit(EXIT_SUCCESS);
}
