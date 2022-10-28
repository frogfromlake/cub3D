/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_deletes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:50:54 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:01:39 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	exit_game_2(t_data *game)
{
	if (game->wall_heights)
		free(game->wall_heights);
	if (game->wall_types)
		free(game->wall_types);
	if (game->wall_shade)
		free(game->wall_shade);
	if (game->map.paths[0])
		free(game->map.paths[0]);
	if (game->map.paths[1])
		free(game->map.paths[1]);
	if (game->map.paths[2])
		free(game->map.paths[2]);
	if (game->map.paths[3])
		free(game->map.paths[3]);
}

void	exit_game(t_data *game)
{
	int	i;

	i = 0;
	close(game->map.map_fd);
	exit_game_2(game);
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
	if (game->mlx)
		mlx_close_window(game->mlx);
	exit(EXIT_SUCCESS);
}
