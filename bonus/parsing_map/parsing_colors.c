/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:32:26 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 20:32:34 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

// helper for read_colour
static void	invalid_colours(t_data *data, char *str)
{
	if (str[0] == 'F' || str[0] == 'f')
	{
		free(str);
		error(data, "\033[0;31mError: Invalid floor colour code.\e[0m\n");
	}
	if (str[0] == 'C' || str[0] == 'c')
	{
		free(str);
		error(data, "\033[0;31mError: Invalid ceiling colour code.\e[0m\n");
	}
}

static bool	check_color_syntax(char *str, int i)
{
	int	j;

	j = 0;
	if (str[i] == ',' || str[ft_strlen(str) - 1] == ',')
		return (false);
	while (str[i])
	{
		if ((str[i]) == ' ' || str[i] == '	')
		{
			j++;
			i++;
			continue ;
		}
		if (str[i] == ',' && str[i + 1] == ',')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_color_elements(char **colors)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (colors[i])
	{
		while (colors[i][j])
		{
			if (ft_is_digit(colors[i][j]) == 1)
				count++;
			if ((ft_is_digit(colors[i][j]) == 0
				&& ft_is_space(colors[i][j]) == false)
					|| (ft_is_digit(colors[i][j]) == 1 && count > 3))
				return (false);
			j++;
		}
		count = 0;
		j = 0;
		i++;
	}
	return (true);
}

static void	error_handling(t_data *data, char **colour_array)
{
	if (!colour_array || check_color_elements(colour_array) == false)
	{
		ft_free_array(colour_array, false, false);
		error(data, "\033[0;31mError: Allocation for floor colour"
			" failed.\e[0m\n");
	}
}

// check rgb values and convert them to integer.
int	parsing_color(t_data *data, char *str, int i)
{
	char	**colour_array;
	int		colour[3];
	int		atoi_result;
	int		j;

	j = -1;
	i += 2;
	i += skip_whitespaces(&str[i]);
	if (check_color_syntax(str, i) == false)
		error(data, "\033[0;31mError: Invalid color values.\e[0m\n");
	colour_array = ft_split(&str[i], ',');
	error_handling(data, colour_array);
	while (colour_array[++j])
	{
		if (!ft_atoi_cub(colour_array[j], &atoi_result)
			|| (atoi_result > 255 || atoi_result < 0) || j > 2)
			invalid_colours(data, str);
		colour[j] = atoi_result;
		free(colour_array[j]);
	}
	free(colour_array);
	if (j < 3 || j < 2)
		error(data, "\033[0;31mError: Allocation for colour identifiers"
			" failed.\e[0m\n");
	return (create_trgb(colour[0], colour[1], colour[2]));
}
