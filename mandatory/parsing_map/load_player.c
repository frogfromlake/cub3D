/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:28 by fquist            #+#    #+#             */
/*   Updated: 2022/07/03 19:06:26 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	set_init_player_dir(t_data *game, int x, int y)
{
	if (game->map.map[y][x] == 'N')
	{
		game->map.map[y][x] = '0';
		game->player.p_dir = NORTH;
	}
	else if (game->map.map[y][x] == 'E')
	{
		game->map.map[y][x] = '0';
		game->player.p_dir = EAST;
	}
	else if (game->map.map[y][x] == 'S')
	{
		game->map.map[y][x] = '0';
		game->player.p_dir = SOUTH;
	}
	else if (game->map.map[y][x] == 'W')
	{
		game->map.map[y][x] = '0';
		game->player.p_dir = WEST;
	}
}

// stores player initial pov
int	init_player_values(t_data *data, int x, int y)
{
	static int	playercount;

	if (x == 0 || y == 0)
		return (playercount);
	data->player.p_x = x + 0.5;
	data->player.p_y = y + 0.5;
	data->player.init_pos.x = data->player.p_x;
	data->player.init_pos.y = data->player.p_y;
	set_init_player_dir(data, x, y);
	data->player.old_dir = data->player.p_dir;
	playercount++;
	return (playercount);
}
