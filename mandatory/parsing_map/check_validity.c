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

// checks if the 0 is valid.
void	check_valid_zero(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	if (is_empty_tile(data->map.map[y - 1][x - 1])
		|| is_empty_tile(data->map.map[y - 1][x + 1])
		|| is_empty_tile(data->map.map[y + 1][x - 1])
		|| is_empty_tile(data->map.map[y + 1][x + 1]))
		error(data, "\033[0;31mError: Invalid map configuration.\e[0m\n");
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (is_empty_tile(data->map.map[y + i][x + j]))
				error(data, "\033[0;31mInvalid map configuration.\e[0m\n");
			j++;
		}
		i++;
	}
}

void	check_valid_player_pos(t_data *data, int x, int y)
{
	if (is_empty_tile(data->map.map[y - 1][x - 1])
		|| is_empty_tile(data->map.map[y - 1][x + 1])
		|| is_empty_tile(data->map.map[y + 1][x - 1])
		|| is_empty_tile(data->map.map[y + 1][x + 1])
		|| is_empty_tile(data->map.map[y + 1][x])
		|| is_empty_tile(data->map.map[y - 1][x])
		|| is_empty_tile(data->map.map[y][x + 1])
		|| is_empty_tile(data->map.map[y][x - 1]))
		error(data, "\033[0;31mError: Invalid player position.\e[0m\n");
}
