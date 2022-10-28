/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:28 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 16:38:28 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

// checks validity of x-borders
static int	parsing_x_borders(t_data *data, char *line)
{
	int	i;

	i = 1;
	(void)data;
	while (line[i])
	{
		if (ft_is_space(line[i]) == true)
		{
			i++;
			continue ;
		}
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// checks the validity if the map borders.
static int	parsing_borders(t_data *data)
{
	int	y;

	y = 0;
	if (!parsing_x_borders(data, data->map.map[0]))
		error(data, "\033[0;31mError: Invalid horizontal border: top.\e[0m\n");
	if (data->m_y > 0 && !parsing_x_borders(data, data->map.map[data->m_y - 1]))
	{
		if (!parsing_x_borders(data, data->map.map[data->m_y - 1]))
			error(data, "\033[0;31mError:"
				" Invalid horizontal border: bottom.\e[0m\n");
	}
	while (y < data->m_y)
	{
		if (line_is_whitespace(data->map.map[y]) == false)
		{
			y++;
			continue ;
		}
		if (data->map.map[y][ft_strlen(data->map.map[y]) - 2] != '1'
			&& data->map.map[y][ft_strlen(data->map.map[y]) - 2] != 'P')
			error(data, "\033[0;31mError: Invalid vertical border.\e[0m\n");
		y++;
	}
	return (1);
}

static void	parsing_lines(t_data *game, int x, int y)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != 'P'
		&& !ft_is_space(game->map.map[y][x]))
	{
		if (game->map.map[y][x] == '0')
			check_valid_zero(game, x, y);
		else if (is_player(game->map.map[y][x]))
		{
			check_valid_player_pos(game, x, y);
			player_values(game, x, y);
		}
		else if (is_sprite(game->map.map[y][x], true))
			parse_sprites(game->map.map[y][x], game, x, y);
		else
			error(game, "\033[0;31minvalid map character.\e[0m\n");
	}
	else if (game->map.map[y][x] == 'P')
	{
		game->portal->portal_nbr++;
		set_portal_data(game, x, y);
	}
}

// loops through stored map and checks validity
void	parsing_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	parsing_borders(data);
	while (++y < data->m_y)
	{
		x = 1;
		while (data->map.map[y][x])
		{
			parsing_lines(data, x, y);
			x++;
		}
	}
	if (player_values(data, 0, 0) != 1)
	{
		if (data->map.map[data->m_y - 1] && data->m_y == 0)
			free(data->map.map[y - 1]);
		error(data, "\033[0;31mInvalid amount of players.\e[0m\n");
	}
	if (data->portal->portal_nbr == 1 || data->portal->portal_nbr > 40)
		error(data, "\033[0;31mInvalid amount of portals."
			" You need at least 2. Odd numbers are not valid.\e[0m\n");
}
