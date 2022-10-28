/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_file_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:32:26 by fquist            #+#    #+#             */
/*   Updated: 2022/07/08 22:19:07 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	check_tab(char *str);

// helper to check_identifiers: store texture paths.
static void	loading_texture_params(t_data *data, int dir, char *str, int i)
{
	if (dir == NORTH)
	{
		data->map.paths[NORTH] = parsing_path(data, str, i);
		data->map.no = true;
	}
	if (dir == SOUTH)
	{
		data->map.paths[SOUTH] = parsing_path(data, str, i);
		data->map.so = true;
	}
	if (dir == EAST)
	{
		data->map.paths[EAST] = parsing_path(data, str, i);
		data->map.ea = true;
	}
	if (dir == WEST)
	{
		data->map.paths[WEST] = parsing_path(data, str, i);
		data->map.we = true;
	}
}

// helper to check_identifiers: store color values.
static void	loading_color_params(t_data *data, int canvas, char *str, int i)
{
	if (canvas == 1)
	{
		data->map.f_colour = parsing_colour(data, str, i);
		data->map.f = true;
	}
	if (canvas == 2)
	{
		data->map.c_colour = parsing_colour(data, str, i);
		data->map.c = true;
	}
}

// check identifiers and store them.
static void	check_identifiers(t_data *data, char *str)
{
	int	i;

	i = 0;
	str[ft_strlen(str) - 1] = '\0';
	i = skip_whitespaces(&str[i]);
	if (!ft_strncmp(str, "NO ", 3) && data->map.no == false)
		loading_texture_params(data, NORTH, str, i);
	else if (!ft_strncmp(str, "EA ", 3) && data->map.ea == false)
		loading_texture_params(data, EAST, str, i);
	else if (!ft_strncmp(str, "SO ", 3) && data->map.so == false)
		loading_texture_params(data, SOUTH, str, i);
	else if (!ft_strncmp(str, "WE ", 3) && data->map.we == false)
		loading_texture_params(data, WEST, str, i);
	else if (!ft_strncmp(str, "F ", 2) && data->map.f == false)
		loading_color_params(data, 1, str, i);
	else if (!ft_strncmp(str, "C ", 2) && data->map.c == false)
		loading_color_params(data, 2, str, i);
	else
	{
		free(str);
		error(data, "\033[0;31mError: Map identifiers invalid.\e[0m\n");
	}
}

// loops through identifiers.
int	parsing_identifiers(t_data *data)
{
	char	*str;
	int		line_count;
	int		i;

	i = 0;
	line_count = 0;
	while (line_count < 6)
	{
		str = get_next_line(data->map.map_fd);
		if (!str)
		{
			free(str);
			error(data, "\033[0;31mError: Couldn't read map.\e[0m\n");
		}
		if (line_is_whitespace(str) == false && no_whitespaces(str) == true)
		{
			line_count++;
			check_identifiers(data, str);
			free(str);
			i++;
		}
		else
			free(str);
	}
	return (i);
}

// loops through map and stores its content in the map struct.
void	loading_map(t_data *data)
{
	int		i;
	int		line;
	char	*str;

	i = 0;
	line = 0;
	while (line != EOF)
	{
		str = get_next_line(data->map.map_fd);
		if (!str)
			line = EOF;
		else if (line_is_whitespace(str) == false && check_tab(str) == true)
		{
			data->map.map[i] = ft_strdup(str);
			free(str);
			i++;
		}
		else
			free(str);
	}
	if (i == 0 && !str)
		error(data, "\033[0;31mError:"
			" Map is empty.\e[0m\n");
	data->map.created = true;
}
