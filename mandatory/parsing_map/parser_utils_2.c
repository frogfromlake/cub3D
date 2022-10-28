/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:19:22 by fquist            #+#    #+#             */
/*   Updated: 2022/07/05 18:57:33 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	is_empty_tile(char tile)
{
	if (tile == ' ' || tile == '\0' || tile == '	' || tile == '\n')
		return (1);
	return (0);
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// helper for player values
int	is_player(char tile)
{
	if (tile == 'N')
		return (1);
	if (tile == 'E')
		return (1);
	if (tile == 'S')
		return (1);
	if (tile == 'W')
		return (1);
	return (0);
}

int	is_sprite(char c)
{
	if (c == 'F' || c == '2' || c == '3'
		|| c == '4' || c == '5' || c == '6'
		|| c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

bool	no_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == true)
			i++;
		else
			return (true);
	}
	return (false);
}
