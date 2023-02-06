/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:25:27 by gohar             #+#    #+#             */
/*   Updated: 2023/02/06 22:24:07 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	init_data(t_data *game)
{
	init_game_variables(game);
	init_enemy_variables(game);
	load_texture_pngs(game);
	create_images(game);
	load_images(game);
	set_mlx_images(game);
	load_minimap_pngs(game);
	load_enemy_sprite_pngs(game);
	put_images_to_window(game);
	mlx_start_sound(0, "afplay -v 0.6 ./bonus/audio/Falling_in_reverse_Drugs.mp3 &");
	game->player.pid[0] = mlx_get_pid("./bonus/audio/Falling_in_reverse_Drugs.mp3");
	game->player.pid[1] = 0;
	game->player.pid[2] = 0;
	game->player.pid[3] = mlx_get_pid("./bonus/audio/Gun.mp3");
	game->player.pid[4] = mlx_get_pid("./bonus/audio/reload.mp3");
	return (0);
}