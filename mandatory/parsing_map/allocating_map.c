/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:28 by fquist            #+#    #+#             */
/*   Updated: 2022/07/08 22:17:11 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	fuck_norm(t_data *data, int i, char *str, int *lines);
void	fuck_norm_2(t_data *data, int *lines);

static void	skip_textures(t_data *data)
{
	char	*str;
	int		line_count;

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
			free(str);
		}
		else
			free(str);
	}
}

static void	skip_trailing_ws(t_data *data, int i, char *str)
{
	while (1)
	{
		if (!str)
			break ;
		if (line_is_whitespace(&str[i]) == false)
		{
			i++;
			continue ;
		}
		if (str[i] != '\n')
			error(data, "\033[0;31mError:"
				" Invalid Character. Check your map.cub\e[0m\n");
		else
			break ;
	}
}

// gets map x and y size.
static void	get_dimensions(t_data *data)
{
	int		i;
	int		lines;
	char	*str;

	i = 0;
	lines = 0;
	while (1)
	{
		str = get_next_line(data->map.map_fd);
		if (!str)
			break ;
		if (ft_strlen(str) > 0 && ((str[0] == ' ') || (str[0] == '1')))
			fuck_norm(data, i, str, &lines);
		else if (ft_strlen(str) > 2 && ((str[0] == ' ') || (str[0] != '1')))
			fuck_norm_2(data, &lines);
		else
			skip_trailing_ws(data, i, str);
		free(str);
	}
	data->m_y = lines;
}

//	check fd, datatype. Skips texture input and gets y-dimension
//	to allocate map-array.
void	allocating_map(t_data *data, char **argv)
{
	data->map.map_fd = open(argv[1], O_RDONLY);
	if (data->map.map_fd < 0)
		error(data, "\e[0;31mError:\nMap not found."
			" Please check your input.\e[0m\n");
	else if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		error(data, "\e[0;31mError:\n"
			"Input datatype is expected to be '.cub'\e[0m\n");
	skip_textures(data);
	get_dimensions(data);
	close(data->map.map_fd);
	data->map.map = malloc(data->m_y * sizeof(char *));
	if (!data->map.map)
		malloc_error(data, "map");
}
