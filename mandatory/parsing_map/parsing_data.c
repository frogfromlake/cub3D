/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:49:05 by fquist            #+#    #+#             */
/*   Updated: 2022/07/03 17:11:31 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	parsing_data(t_data *data, int argc, char **argv)
{
	(void)argc;
	data->map.map_fd = open(argv[1], O_RDONLY);
	if (data->map.map_fd < 0)
		error(data, "\e[0;31mError\nMap not found."
			" Please check your input.\e[0m\n");
	parsing_identifiers(data);
	loading_map(data);
	parsing_map(data);
	close(data->map.map_fd);
	return ;
}
