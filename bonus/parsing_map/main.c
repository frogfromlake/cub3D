/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:18:52 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 16:09:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_mouse		mouse;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&mouse, 0, sizeof(t_mouse));
	allocating_map(&data, argv);
	parsing_data(&data, argc, argv);
	init_data(&data);
	calculating_walls(&data);
	rendering_world(&data);
	draw_minimap(&data);
	mlx_loop_hook(data.mlx, &key_hook, &data);
	mlx_cursor_hook(data.mlx, &mouse_controls, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	return (0);
}
