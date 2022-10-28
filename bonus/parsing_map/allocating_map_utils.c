/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:25:09 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 20:25:28 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	fuck_norm(t_data *data, int i, char *str, int *lines)
{
	(*lines)++;
	i = 0;
	while (str[i])
		i++;
	if ((i - 1) > data->m_x)
		data->m_x = i - 1;
}

void	fuck_norm_2(t_data *data, int *lines)
{
	(*lines)++;
	error(data, "\033[0;31mError: Invalid map character.\e[0m\n");
}
