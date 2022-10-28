/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:18:52 by fquist            #+#    #+#             */
/*   Updated: 2022/07/08 22:46:16 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// slow down loop hook for higher fps?
int	main(int argc, char **argv)
{
	t_data		data;

	ft_memset(&data, 0, sizeof(t_data));
	init_variables(&data);
	allocating_map(&data, argv);
	parsing_data(&data, argc, argv);
	load_images(&data);
	calculating_walls(&data);
	rendering_world(&data);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	return (0);
}
