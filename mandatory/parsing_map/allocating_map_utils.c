/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:22:31 by fquist            #+#    #+#             */
/*   Updated: 2022/07/08 21:47:32 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
